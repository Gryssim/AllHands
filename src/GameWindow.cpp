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

//#include <SDL.h>
//#include <SDL_image.h>
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>

#include "../include/GameWindow.h"

using namespace std;

GameWindow::GameWindow(int width, int height, string winTitle){
    m_WinWidth = width;
    m_WinHeight = height;
    m_WinTitle = winTitle;
    //Set pointers to null until init() is called to create window and renderer. 
    m_Window = NULL;
    m_Renderer = NULL;
}

GameWindow::~GameWindow(){

}

bool GameWindow::init(){
	bool success = true;

	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		printf("Unable to initialize SDL! SDL Error: %s\n", SDL_GetError());
		success = false;
	} else {
		//create window
		m_Window = SDL_CreateWindow(
			m_WinTitle.c_str(), 				// Replace with window title
			SDL_WINDOWPOS_UNDEFINED, 	//Window x pos
			SDL_WINDOWPOS_UNDEFINED, 	//window y pos
			m_WinWidth,
			m_WinHeight,
			SDL_WINDOW_OPENGL        	//Window flags
		);
		if(m_Window == NULL){
			printf("Unable to create new window! SDL Error: %s\n", SDL_GetError());
			success = false;
		} else {
			//Create renderer
			m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
			if(m_Renderer == NULL){
				printf("Unable to create renderer! SDL Error: %s\n", SDL_GetError());
				success = false;
			} else {
				//init renderer

				int imgFlags = IMG_INIT_PNG;
				if(!(IMG_Init(imgFlags) & imgFlags)){
					printf("SDL_Image could not start! SDL Error: %s\n", SDL_GetError());
					success = false;
				}
				
			}
		}
	}
	return success;
}
//Not sure if this will be needed as we'll load textures as we create Texture objects?
//Or should we offload all sprite loading to the window class...
//I feel we want explicit references to the sprites to update them.
//Leaving in class until we make a decision on this.
bool GameWindow::loadMedia(){
	bool success = true;

	return success;
}

//window.close will terminate the window. Call on exit of program. (Maybe rethink name of class?)
void GameWindow::close(){
    SDL_DestroyWindow(m_Window);
    SDL_DestroyRenderer(m_Renderer);
    m_Window = NULL;
    m_Renderer = NULL;

    IMG_Quit();
    SDL_Quit();
}

SDL_Window* GameWindow::getWindow(){
	return m_Window;
}

SDL_Renderer* GameWindow::getRenderer(){
	return m_Renderer;
}

int GameWindow::getWindowHeight(){
	return m_WinHeight;
}

int GameWindow::getWindowWidth(){
	return m_WinWidth;
}