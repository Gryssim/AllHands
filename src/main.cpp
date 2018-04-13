#ifdef __linux__ 
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#elif _WIN32
#include <SDL.h>
#include <SDL_image.h>
#else

#endif

#include "../include/Game.h"

int main(int argc, char* argv[]){
	Game game;
	game.run();

	//bool quit = false;
	//GameWindow window(800, 600, "GameWindow");
	//World gameWorld;

	/*
	if(!window.init()){
		printf("Unable to initialize GameWindow!");
	} else {
		gameWorld.loadMedia(window.getRenderer());
		gameWorld.createCrew();
		gameWorld.createShip();
		SDL_Event event;

		while(!quit){
			Uint32 start = SDL_GetTicks();
			while(SDL_PollEvent(&event) != 0){
				if(event.type == SDL_QUIT){
					quit = true;
				}
				else if(event.type == SDL_KEYDOWN){
					switch(event.key.keysym.sym){
						case SDLK_UP:
							gameWorld.getCamera()->moveCamera(0, -1);
							break;
						case SDLK_LEFT:
							gameWorld.getCamera()->moveCamera(-1, 0);
							break;
						case SDLK_RIGHT:
							gameWorld.getCamera()->moveCamera(1, 0);
							break;
						case SDLK_DOWN:
							gameWorld.getCamera()->moveCamera(0, 1);
							break;
					}
				}
				else if(event.type == SDL_KEYUP){
					switch(event.key.keysym.sym){
						case SDLK_UP:
							gameWorld.getCamera()->stopMove();
							break;
						case SDLK_LEFT:
							gameWorld.getCamera()->stopMove();
							break;
						case SDLK_RIGHT:
							gameWorld.getCamera()->stopMove();
							break;
						case SDLK_DOWN:
							gameWorld.getCamera()->stopMove();
							break;
					}
				}
			}
			SDL_SetRenderDrawColor(window.getRenderer(), 0x00, 0x00, 0x20, 0xFF);
			SDL_RenderClear(window.getRenderer());
			gameWorld.update();
			gameWorld.draw(window.getRenderer());

			SDL_RenderPresent(window.getRenderer());

			if((1000 / 60) > (SDL_GetTicks() - start)){
				SDL_Delay((1000/60)- (SDL_GetTicks() - start ));
			}
		}

		window.close();
	}
	*/
	return 0;
}