#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <string>
#include <stdio.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

bool init();

bool loadMedia();

void close();

int main(int argc, char* argv[]){
	
	
	return 0;
}

bool init(){
	bool success = true;

	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		printf("Unable to initialize SDL! SDL Error: %s\n", SDL_GetError());
		success = false;
	} else {
		//create window
		gWindow = SDL_CreateWindow(
			"Hello World", 				// Replace with window title
			SDL_WINDOWPOS_UNDEFINED, 	//Window x pos
			SDL_WINDOWPOS_UNDEFINED, 	//window y pos
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_OPENGL        	//Window flags
		);
		if(gWindow == NULL){
			printf("Unable to create new window! SDL Error: %s\n", SDL_GetError());
			success = false;
		} else {
			//Create renderer
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if(gRenderer == NULL){
				printf("Unable to create renderer! SDL Error: %s\n", SDL_GetError());
				success = false;
			} else {
				//init renderer
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

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

bool loadMedia(){
	bool success = true;

	return success;
}

void close(){

}
