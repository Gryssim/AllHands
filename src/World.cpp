
#include <string>
#include <stdlib.h>
#include <time.h>

#include "../include/World.h"
#include "../include/Hand.h"


World::World(){
    m_WorldWidth = 800 * 4;
    m_WorldHeight = 600 * 4;
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

void World::createShip(){
    
    for(int i = 0; i < 5; i ++){
        ShipTile newTile(t_TestTileTexture, Med_Bay, (i * 74) + 100, 300);
        m_Ship.addTile(newTile);
    }
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
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x20, 0xFF);
    m_Ship.draw(renderer, &m_Camera);
    m_Crew.draw(renderer, &m_Camera);
}

void Hand::handleMovement() // Levi
{
	int x = rand() % 4;
		switch (x)
		{
		case 0: m_VelY -= HAND_VEL; break;
		case 1: m_VelY += HAND_VEL; break;
		case 2: m_VelX -= HAND_VEL; break;
		case 3: m_VelX += HAND_VEL; break;
		}
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

Camera* World::getCamera(){
    return &m_Camera;
}