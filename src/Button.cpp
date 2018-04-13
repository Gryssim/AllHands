
#include "../include/Button.h"

Button::Button(SDL_Renderer* renderer, int x, int y, string title){
    string basePath = "";

    if (getenv("windir") != NULL) basePath = "assets\\sprites\\";
	else basePath= "../assets/sprites/";

    m_ButtonTexture.loadFromFile(renderer, basePath + "Button.png");

    //Set positions
    m_xPos = x;
    m_yPos = y;

    //set string
    m_ButtonTitle = title;

}

Button::~Button(){

}

void Button::draw(SDL_Renderer* renderer){
    m_ButtonTexture.draw(renderer, m_xPos, m_yPos);
}

int Button::getXPos(){
    return m_xPos;
}

int Button::getYPos(){
    return m_yPos;
}