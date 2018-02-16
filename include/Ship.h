#ifndef SHIP_H
#define SHIP_H

#include "../include/Vector2.h"
#include "../include/Texture.h"

class Ship{
    public:
    Ship(Texture* texture);
    ~Ship();

    void draw(SDL_Renderer* renderer, int xPos, int yPos);
    void draw(SDL_Renderer* renderer, Vector2 pos);

    //Will probably have a bunch of other member methods that have to do with malfunctions, damage, 
    // etc.
    
    int getTextureWidth();
    int getTextureHeight();

    int getHull();

    private:
    int m_Hull;
    Texture* m_ShipTexture;
};

#endif