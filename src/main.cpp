#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <string>
#include <stdio.h>

#include "../include/GameWindow.h"
#include "../include/Texture.h"
#include "../include/Hand.h"
#include "../include/Crew.h"
#include "../include/Ship.h"

int main(int argc, char* argv[]){
	bool quit = false;
	GameWindow window(800, 600, "GameWindow");
	Texture* testTile = new Texture;
	Texture* captTexture = new Texture;
	Texture* engTexture = new Texture;
	Texture* redShirtTexture = new Texture;
	Texture* shipTexture = new Texture;
	Crew testCrew;

	if(!window.init()){
		printf("Unable to initialize GameWindow!");
	} else {
		captTexture->loadFromFile(window.getRenderer(), "../assets/sprites/Captain.png");
		shipTexture->loadFromFile(window.getRenderer(), "../assets/Ships/Ship_0001.png");
		if(engTexture->loadFromFile(window.getRenderer(), "../assets/sprites/Engineer.png")){
			printf("Eng loaded successfully.\n");
		}
		redShirtTexture->loadFromFile(window.getRenderer(), "../assets/sprites/RedShirt.png");
		Hand testHand(captTexture, CAPTAIN, 50, 50);
		Ship testShip(shipTexture);

		//Create crew
		for(int i = 0; i < testCrew.getMaxCrew(); ++i){
			//printf("%i\n", i);

			Hand newHand(engTexture, ENGINEER, (i * 10) + 10, window.getWindowHeight() / 2);
			testCrew.addHand(newHand);
		}

		SDL_Event event;

		while(!quit){
			while(SDL_PollEvent(&event) != 0){
				if(event.type == SDL_QUIT){
					quit = true;
				}
			}
			SDL_SetRenderDrawColor(window.getRenderer(), 0x25, 0x35, 0x50, 0xFF);
			SDL_RenderClear(window.getRenderer());

			//testTexture.draw(window.getRenderer(), window.getWindowWidth() / 2, window.getWindowHeight() / 2);
			//testShip.draw(window.getRenderer(), window.getWindowWidth() / 2, window.getWindowHeight() / 2);
			//shipTexture->draw(window.getRenderer(), 50, 50);
			//testHand.draw(window.getRenderer());

			testCrew.draw(window.getRenderer());

			SDL_RenderPresent(window.getRenderer());
		}
		captTexture->free();
		engTexture->free();
		redShirtTexture->free();
		shipTexture->free();
		window.close();
	}
	
	return 0;
}