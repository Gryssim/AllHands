#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <string>
#include <stdio.h>

#include "../include/GameWindow.h"
#include "../include/World.h"

int main(int argc, char* argv[]){
	bool quit = false;
	GameWindow window(800, 600, "GameWindow");
	World gameWorld;

	
	if(!window.init()){
		printf("Unable to initialize GameWindow!");
	} else {
		gameWorld.loadMedia(window.getRenderer());

		SDL_Event event;

		while(!quit){
			while(SDL_PollEvent(&event) != 0){
				if(event.type == SDL_QUIT){
					quit = true;
				}
			}
			SDL_SetRenderDrawColor(window.getRenderer(), 0x00, 0x00, 0x20, 0xFF);
			SDL_RenderClear(window.getRenderer());
			gameWorld.createCrew();
			gameWorld.createShip();
			gameWorld.update();
			gameWorld.draw(window.getRenderer());

			SDL_RenderPresent(window.getRenderer());
			SDL_Delay(1000/60);
		}

		window.close();
	}
	
	return 0;
}