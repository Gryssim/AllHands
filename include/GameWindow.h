#ifdef __linux__ 
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#elif _WIN32
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#else

#endif
#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H
//#include <SDL.h>
//#include <SDL_image.h>
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>

#include "../include/Texture.h"

using namespace std;

class GameWindow {
    public:
    GameWindow(int width, int height, string winTitle);
    ~GameWindow();

    bool init();

    bool loadMedia();

    void close();

    SDL_Window* getWindow();
    SDL_Renderer* getRenderer();

    int getWindowHeight();
    int getWindowWidth();

    private:

    SDL_Window* m_Window;
    SDL_Renderer* m_Renderer;

    TTF_Font* m_Font;

    int m_WinHeight;
    int m_WinWidth;

    string m_WinTitle;
};

#endif