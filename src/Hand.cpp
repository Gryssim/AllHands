#include "../include/Hand.h"
#include "../include/Texture.h"

Hand::Hand(Texture* texture, HandOccupation job){
    m_xPos = 0;
    m_yPos = 0;
    m_HandTexture = texture;
    m_Job = job;
}

Hand::Hand(Texture* texture, HandOccupation job, int xPos, int yPos){
    m_xPos = xPos;
    m_yPos = yPos;
    m_HandTexture = texture;
    m_Job = job;
}

Hand::Hand(Texture* texture, HandOccupation job, Vector2 pos){
    m_xPos = pos.getX();
    m_yPos = pos.getY();
    m_HandTexture = texture;
    m_Job = job;
}

Hand::~Hand(){
    m_HandTexture->free();
    m_HandTexture = NULL;
}

bool Hand::operator==(const Hand& rightHand) const{
    return this->m_Id == rightHand.m_Id;
}

void Hand::draw(SDL_Renderer* renderer){
    //printf("Hand Pos: x - %i    y - %i\n", m_xPos, m_yPos);
    m_HandTexture->draw(renderer, m_xPos, m_yPos);
}

int Hand::getId(){
    return m_Id;
}

Vector2 Hand::getXYPos(){
    return Vector2(m_xPos, m_yPos);
}

int Hand::getX(){
    return m_xPos;
}

int Hand::getY(){
    return m_yPos;
}


Texture* Hand::getTexture(){
    return m_HandTexture;
}