#ifdef __linux__ 
	#include <SDL2/SDL_image.h>
	#include <SDL2/SDL.h>
#elif _WIN32
	#include <SDL.h>
	#include <SDL_image.h>
#else

#endif
#ifndef TEXTURE_H
#define TEXTURE_H

//#include <SDL.h>
//#include <SDL2/SDL.h>
#include <string>

#include "../include/Vector2.h"

using namespace std;

class Texture{
    public:
    //Constructor
    Texture();
    //Deconstructor
    ~Texture();
    
    //Load desired portion of sprite sheet
    bool LoadFromSheet(SDL_Renderer* renderer, string path, SDL_Rect srcRect);

    //Load desired image (png) from specified path
    bool loadFromFile(SDL_Renderer* renderer, string path);

    //For deleting a texture, free up resources.
    void free();

    //draw the texture
    void draw(SDL_Renderer* renderer, int xPos, int yPos);
    void draw(SDL_Renderer* renderer, Vector2 pos);

    //Alter textures color
    void changeTextureColorByRGB(int r, int g, int b);

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