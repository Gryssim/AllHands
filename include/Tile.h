#ifndef TILE_H
#define TILE_H

#include <SDL2/SDL.h>

#include "../include/Texture.h"

class Tile{
    public:
    Tile(int xPos, int yPos);
    ~Tile();

    void draw(SDL_Renderer* renderer, int xPos, int yPos);
    void draw(SDL_Renderer* renderer, Vector2 pos);

    private:
    int m_xPos, m_yPos;
    Texture* m_TileTexture;
};

#endif