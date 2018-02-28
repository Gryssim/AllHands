
#include <string>

#include "../include/World.h"
#include "../include/Hand.h"


World::World(){

}

World::~World(){

}

bool World::loadMedia(SDL_Renderer* renderer){
    bool success = true;
    string basePath = "../assets/sprites/";
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
    m_Ship.draw(renderer);
    m_Crew.draw(renderer);
}

void World::update(){

}

void World::updateBackground(){

}