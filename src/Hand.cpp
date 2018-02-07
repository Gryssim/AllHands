#include "../include/Hand.h"
#include "../include/Texture.h"

Hand::Hand(Texture* texture, HandOccupation job){
    m_HandTexture = texture;
    m_Job = job;
}

Hand::~Hand(){

}

int Hand::getId(){
    return m_Id;
}

Texture* Hand::getTexture(){
    return m_HandTexture;
}