
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>

#include "../include/World.h"


World::World(){
    m_WorldWidth = 800 * 4;
    m_WorldHeight = 600 * 4;
    m_CurrentFloor = 0;
    initBackground();
}

World::~World(){

}

bool World::loadMedia(SDL_Renderer* renderer){
    bool success = true;
	string basePath;
	if (getenv("windir") != NULL) basePath = "assets\\sprites\\";
	else basePath= "../assets/sprites/";
    t_TestTileTexture = new Texture;
    if(!(t_TestTileTexture->loadFromFile(renderer, basePath + "ShipTileProto.png" ))){
        success = false;
    }
    //Loads all crewman sprites (Currently no animation, basic sprites)
    for(int i = 0; i < OCCUPATION_COUNT; ++i){
        string occupationString = HandOccupationToString((HandOccupation) i);
        occupationString[0] -= 32;
        Texture* tempTexture = new Texture;
        if(!(tempTexture->loadFromFile(renderer, basePath + occupationString + ".png"))){
            success = false;
        } else {
            //Load texture into map with occupation.
            m_HandTextureMap.insert(pair<HandOccupation, Texture*>((HandOccupation) i, tempTexture));
        }
    }

    return success;
}

void World::createShip(string shipFile){
    ifstream inf(shipFile.c_str());
    int floor, j = 0;
    string row;
    //Read Line by Line until eof
    //if first character is ! set floor to next char
    //Set tiles by position in string 
    //  (x = char index * tile Size + offset, y = char row * tile Size + offset) 
    while(getline(inf, row)){
        //printf("%s\n", row.c_str());
        if(row[0] == '!'){
            floor = (int) row[1] - 48;
            j = 0;
        } else {
            for(int i = 0; i < row.size(); ++i){
                if(row[i] == ' '){
                    continue;
                } else {
                    ShipTile newTile(
                        ShipTile::get_marker_class(row[i]),
                        floor,
                        (i * 25) + (100), //x pos
                        (j * 25) + (300 + (floor * 20))  //y pos
                        );
                    //printf("x:%i y:%i floor: %i\n", newTile.get_posX(), newTile.get_posY(), floor);
                    m_Ship.addTile(newTile);
                }
            }
            j++;
        }
        m_NumFloors = floor;
    }
    /*
    for(int j = 0; j < 5; j++){
       for(int i = 0; i < 20; i++){
            ShipTile newTile(Med_Bay, 1, (i * 25) + 100, (j * 25) + 300);
        m_Ship.addTile(newTile);
        }
    }
    */
}

void World::createCrew(){
    for(int i = 0; i < m_Crew.getMaxCrew(); ++i){
        Hand newHand(m_HandTextureMap[ENGINEER], ENGINEER, (i * 10) + 10, 300);
        m_Crew.addHand(newHand);
    }
}

void World::draw(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    for(int i = 0; i < MAX_STARS; ++i){
        /*
        if(((m_Stars[i].posX < m_Camera.getCamPosX() + 800) &&
            (m_Stars[i].posX > m_Camera.getCamPosX())) && 
            (m_Stars[i].posY < m_Camera.getCamPosY() + 600) &&
            (m_Stars[i].posY > m_Camera.getCamPosY())){
        */
        if(i % 10 == 0){
            //Closest stars -- scale by 5
            drawStar(renderer, m_Stars[i], 3);                        
        } 
        else if(i % 5 == 0){
            //Next stars back -- scale default by 2
            drawStar(renderer, m_Stars[i], 2);
        }
        else {
            //furthest stars -- each rect maybe 2px x 4px?
            drawStar(renderer, m_Stars[i], 1);
        }
        //} End of bounding if
    }
    m_Ship.draw(renderer, &m_Camera, m_CurrentFloor);
    m_Crew.draw(renderer, &m_Camera);
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x20, 0xFF);
}

void World::drawStar(SDL_Renderer* renderer, backgroundStar star, int scale){
    int defLength = 4, defWidth = 2;
    SDL_Rect vertRect = {
        star.posX - ((defWidth / 2)* scale),    //x
        star.posY,                             //y
        defLength * scale,                      //h
        defWidth * scale                        //w
    }; 
    SDL_Rect horRect = {
        star.posX,                              //x
        star.posY - ((defWidth / 2) * scale),   //y
        defWidth * scale,                       //h
        defLength * scale                       //w
    };         
    SDL_RenderFillRect(renderer, &vertRect);
    SDL_RenderFillRect(renderer, &horRect);
}

void World::update(){
    updateBackground();
    m_Camera.update();
}

void World::initBackground(){
    srand(time(NULL));
    for(int i = 0; i < MAX_STARS; ++i){
        m_Stars[i].posX = rand() % 800 + 1;
        m_Stars[i].posY = rand() % 600 + 1;
    }
}

void World::updateBackground(){
    for(int i = 0; i < MAX_STARS; ++i){
        if(i % 10 == 0){
            //Close stars
            m_Stars[i].posX -= 3;
        } 
        else if(i % 5 == 0){
            //Next stars back
            m_Stars[i].posX -= 2;
        }
        else {
            //furthest stars
            m_Stars[i].posX -= 1;
        }
        if(m_Stars[i].posX <= -5){
            m_Stars[i].posX = 810;
            m_Stars[i].posY = rand() % 600 + 1;
        }
    }
}

int World::getCurrentFloor(){
    return m_CurrentFloor;
}

int World::getNumFloors(){
    return m_NumFloors;
}

///Change floor by input number, if negative move towards top floors, if positive
/// move towards bottom floors. If 0, reset to top
void World::changeFloor(int changeFloorBy){
    if((m_CurrentFloor + changeFloorBy) <= m_NumFloors && (m_CurrentFloor + changeFloorBy) >= 0){
        if(changeFloorBy != 0){
            m_CurrentFloor += changeFloorBy;
        } else {
            m_CurrentFloor = 0;
        }
    } else {
        printf("Unable to change floor.\n");
    }
}

Camera* World::getCamera(){
    return &m_Camera;
}