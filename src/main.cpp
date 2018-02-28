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
	//Texture* testTile = new Texture;
	//Texture* captTexture = new Texture;
	//Texture* engTexture = new Texture;
	//Texture* redShirtTexture = new Texture;
	//Texture* shipTexture = new Texture;
	//Crew testCrew;
	
	if(!window.init()){
		printf("Unable to initialize GameWindow!");
	} else {
		gameWorld.loadMedia(window.getRenderer());
		//captTexture->loadFromFile(window.getRenderer(), "../assets/sprites/Captain.png");
		//shipTexture->loadFromFile(window.getRenderer(), "../assets/Ships/Ship_0001.png");
		//engTexture->loadFromFile(window.getRenderer(), "../assets/sprites/Engineer.png");
		//redShirtTexture->loadFromFile(window.getRenderer(), "../assets/sprites/RedShirt.png");
		//Hand testHand(captTexture, CAPTAIN, 50, 50);
		//Ship testShip(shipTexture);
		/*
		//Create crew
		for(int i = 0; i < testCrew.getMaxCrew(); ++i){
			Hand newHand(engTexture, ENGINEER, (i * 10) + 10, window.getWindowHeight() / 2);
			testCrew.addHand(newHand);
		}
		*/

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
			gameWorld.draw(window.getRenderer());
			//testCrew.draw(window.getRenderer());

			SDL_RenderPresent(window.getRenderer());
			SDL_Delay(1000/60);
		}
		//captTexture->free();
		//engTexture->free();
		//redShirtTexture->free();
		//shipTexture->free();
		window.close();
	}
	
	return 0;
}

/*

frame start

do updates
do draws

frame length = start - now


*/