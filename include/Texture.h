#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
#include <string>

using namespace std;

class Texture{
    public:
    //Constructor
    Texture();
    //Deconstructor
    ~Texture();
    
    //Load desired image (png) from specified path
    bool loadFromFile(SDL_Renderer* renderer, string path);

    //For deleting a texture, free up resources.
    void free();

    //draw the texture
    void draw(SDL_Renderer* renderer, int xPos, int yPos);

    //get dimensions of image
    int getWidth();
    int getHeight();

    private:
    SDL_Texture* m_Texture;
    SDL_Renderer* m_Renderer;
    int m_Width;
    int m_Height;
};

#endif