#include "../include/Ship.h"


Ship::Ship(){
    m_Hull = 100;
}

Ship::~Ship(){

}

void Ship::addTile(ShipTile tile){
    m_ShipTiles.push_back(tile);
}

void Ship::draw(SDL_Renderer* renderer, Camera* cam){
    for (int i = 0; i < m_ShipTiles.size(); ++i){
        if(((m_ShipTiles[i].get_posX() < cam->getCamPosX() + 800 + 150) &&
            (m_ShipTiles[i].get_posX() > cam->getCamPosX() - 100)) &&
            ((m_ShipTiles[i].get_posY() < cam->getCamPosY() + 600 + 150) &&
            (m_ShipTiles[i].get_posY() > cam->getCamPosY() - 100))){

            m_ShipTiles[i].draw(renderer, cam);
        }
    }
}

int Ship::getHull(){   
    return m_Hull;
}
