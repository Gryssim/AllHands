#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <string>
#include <stdio.h>

#include "../include/GameWindow.h"
#include "../include/Texture.h"


int main(int argc, char* argv[]){
	bool quit = false;
	GameWindow window(800, 600, "GameWindow");
	Texture testTexture;

	if(!window.init()){
		printf("Unable to initialize GameWindow!");
	} else {
		testTexture.loadFromFile(window.getRenderer(), "../assets/sprites/Engineer.png");
		SDL_Event event;

		while(!quit){
			while(SDL_PollEvent(&event) != 0){
				if(event.type == SDL_QUIT){
					quit = true;
				}
			}
			SDL_SetRenderDrawColor(window.getRenderer(), 0x25, 0x65, 0xEF, 0xFF);
			SDL_RenderClear(window.getRenderer());

			testTexture.draw(window.getRenderer(), window.getWindowWidth() / 2, window.getWindowHeight() / 2);

			SDL_RenderPresent(window.getRenderer());
		}
		window.close();
	}
	
	return 0;
}