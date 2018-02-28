#include "../include/Ship.h"


Ship::Ship(){
    m_Hull = 100;
}

Ship::~Ship(){

}

void Ship::addTile(ShipTile tile){
    m_ShipTiles.push_back(tile);
}

void Ship::draw(SDL_Renderer* renderer){
    for (int i = 0; i < m_ShipTiles.size(); ++i){
        m_ShipTiles[i].draw(renderer);
    }
}

int Ship::getHull(){   
    return m_Hull;
}
