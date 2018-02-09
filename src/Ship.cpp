#include "../include/Ship.h"

Ship::Ship(Texture* texture){
    m_ShipTexture = texture;
    m_Hull = 100;
}

Ship::~Ship(){

}

int Ship::getTextureWidth(){
    return m_ShipTexture->getWidth();
}

int Ship::getTextureHeight(){
    return m_ShipTexture->getHeight();
}

void Ship::draw(SDL_Renderer* renderer, int xPos, int yPos){
    //printf("Ship Texture Position - xPos: %i  yPos: %i\n", xPos, yPos);
    m_ShipTexture->draw(renderer, xPos, yPos);
}

int Ship::getHull(){   
    return m_Hull;
}
