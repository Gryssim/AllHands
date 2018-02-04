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

bool Texture::loadFromFile(string path){
    //Remove any existing texture
    free();
    SDL_Texture* newTexture = NULL;

    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == NULL){
        printf("Unable to load texture at %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
    } else {
        newTexture = SDL_CreateTextureFromSurface(m_Renderer, loadedSurface);
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

void Texture::draw(int x, int y){
    //Set rendering space and draw to screen
    SDL_Rect renderQuad = { x, y, m_Width, m_Height };
    SDL_RenderCopy(m_Renderer, m_Texture, NULL, &renderQuad);
}

int Texture::getWidth(){
    return m_Width;
}

int Texture::getHeight(){
    return m_Height;
}