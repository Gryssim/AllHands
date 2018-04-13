#ifdef __linux__ 
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#elif _WIN32
#include <SDL.h>
#include <SDL_image.h>
#include <SDL2/SDL_ttf.h>
#else
#endif

#ifndef BUTTON_H
#define BUTTON_H

#include <string>

#include "../include/Texture.h"

class Button{
    public:
    Button(SDL_Renderer* renderer, int x, int y, string name);
    ~Button();

    void draw(SDL_Renderer* renderer);

    int getXPos();
    int getYPos();

    private:
    int m_xPos, m_yPos;
    Texture m_ButtonTexture;
    string m_ButtonTitle;
};


#endif