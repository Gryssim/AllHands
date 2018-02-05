#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <string>
#include <stdio.h>

#include "../include/GameWindow.h"

bool loadMedia();

int main(int argc, char* argv[]){
	bool quit = false;
	GameWindow window(800, 600, "This is the new window");

	if(!window.init()){
		printf("Unable to initialize GameWindow!");
	} else {
		SDL_Event event;

		while(!quit){
			while(SDL_PollEvent(&event) != 0){
				if(event.type == SDL_QUIT){
					quit = true;
				}
			}
		}
		window.close();
	}
	
	return 0;
}

bool loadMedia(){
	bool success = true;

	return success;
}