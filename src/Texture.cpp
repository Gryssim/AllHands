#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#include "../include/Texture.h"

using namespace std;

Texture::Texture(){
    m_Texture = NULL;
    m_Renderer = NULL;
    m_Width = 0;
    m_Height = 0;
}

Texture::~Texture(){
    free();
}

bool Texture::LoadFromSheet(SDL_Renderer* renderer, string path, SDL_Rect srcRect){
    free();


    return m_Texture != NULL;
}

bool Texture::loadFromFile(SDL_Renderer* renderer, string path){
    //Remove any existing texture
    free();
    SDL_Texture* newTexture = NULL;

    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == NULL){
        printf("Unable to load image at %s! SDL Error: %s\n", path.c_str(), IMG_GetError());
    } else {
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if(newTexture == NULL){
            printf("Unable create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        } else {
            //Load dimensions to object
            m_Width = loadedSurface->w;
            m_Height = loadedSurface->h;
        }
        SDL_FreeSurface(loadedSurface);
    }

    m_Texture = newTexture;
    //printf("Texture dims - w: %i   h: %i\n", m_Width, m_Height);
    return m_Texture != NULL;
}

//Only call free when closing the program or when loading a new texture to reference,
// as many objects will be sharing the textures.
void Texture::free(){
    if(m_Texture != NULL){
        //I don't think we need to destroy the renderer as it'll be used for multiple objects
        SDL_DestroyTexture(m_Texture);
        m_Texture = NULL;
        m_Width = 0;
        m_Height = 0;
    }
}

//Position drawing from center of texture as apposed to top left corner.
void Texture::draw(SDL_Renderer* renderer, int xPos, int yPos){
    if(m_Texture == NULL){
        //printf("This is getting dumb\n");
    }
    //Set rendering space and draw to screen
    SDL_Rect renderQuad = { xPos - m_Width / 2, yPos - m_Height / 2, m_Width, m_Height };
    SDL_RenderCopy(renderer, m_Texture, NULL, &renderQuad);
}

void Texture::draw(SDL_Renderer* renderer, Vector2 pos){
    SDL_Rect renderQuad = { pos.getX() - m_Width / 2, pos.getY() - m_Height / 2, m_Width, m_Height };
    SDL_RenderCopy(renderer, m_Texture, NULL, &renderQuad);
}

int Texture::getWidth(){
    return m_Width;
}

int Texture::getHeight(){
    return m_Height;
}