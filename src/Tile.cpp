#include "../include/Tile.h"

Tile::Tile(int xPos, int yPos){
    m_xPos = xPos;
    m_yPos = yPos;
}

Tile::~Tile(){
    m_TileTexture->free();
    m_TileTexture = NULL;
}

void Tile::draw(SDL_Renderer* renderer, int xPos, int yPos){
    m_TileTexture->draw(renderer, Vector2(m_xPos, m_yPos));
}

void Tile::draw(SDL_Renderer* renderer, Vector2 pos){

}