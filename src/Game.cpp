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

#include <string>
#include <stdio.h>

#include "../include/Game.h"
#include "../include/Button.h"

Game::Game() : m_GameWindow(800, 600, "Game Window"){
    m_GameState = START_MENU;
    m_Quit = false;
}

Game::~Game(){

}

void Game::run(){
    if(!m_GameWindow.init()){
        printf("Unable to initialize GameWindow!\n");
    } else {
        m_GameWorld.loadMedia(m_GameWindow.getRenderer());
        m_GameWorld.createCrew();
        m_GameWorld.createShip("../assets/Ships/ship.shp");
        //printf("Ship created\n");
        SDL_Event event;

        while(!m_Quit){
            Uint32 start = SDL_GetTicks();
            while(SDL_PollEvent(&event) != 0){
                if(event.type == SDL_QUIT){
                    quit();
                }
                else if(event.type == SDL_KEYDOWN){
                    switch(event.key.keysym.sym){
                        case SDLK_UP:
                            m_GameWorld.getCamera()->moveCamera(0, -1);
                            break;
                        case SDLK_LEFT:
                            m_GameWorld.getCamera()->moveCamera(-1, 0);
                            break;
                        case SDLK_RIGHT:
                            m_GameWorld.getCamera()->moveCamera(1, 0);
                            break;
                        case SDLK_DOWN:
                            m_GameWorld.getCamera()->moveCamera(0, 1);
                            break;
                        case SDLK_PERIOD:
                            m_GameWorld.changeFloor(1);
                            break;
                        case SDLK_COMMA:
                            m_GameWorld.changeFloor(-1);
                            break;
                    }
                }
                else if(event.type == SDL_KEYUP){
                    switch(event.key.keysym.sym){
                        case SDLK_UP:
                            m_GameWorld.getCamera()->stopMove();
                            break;
                        case SDLK_LEFT:
                            m_GameWorld.getCamera()->stopMove();
                            break;
                        case SDLK_RIGHT:
                            m_GameWorld.getCamera()->stopMove();
                            break;
                        case SDLK_DOWN:
                            m_GameWorld.getCamera()->stopMove();
                            break;
                    }
                }
            }
            //If state is main menu, instead of rendering game world 
            // Render menu? Could also work for pause.
            // If state is pause menu, render game world without update
            //   and menu on top? Or ditch game world during that state too?
            //   Probably ditch game world.
            if(m_GameState == GAME){
                GameLoop();
            } else if (m_GameState == START_MENU){
                MenuLoop();
            }
            SDL_RenderPresent(m_GameWindow.getRenderer());

            if((1000 / 60) > (SDL_GetTicks() - start)){
                SDL_Delay((1000/60)- (SDL_GetTicks() - start ));
            }
        }
    }
}

void Game::close(){
    m_GameWindow.close();
}

void Game::GameLoop(){
    SDL_SetRenderDrawColor(m_GameWindow.getRenderer(), 0x00, 0x00, 0x20, 0xFF);
    SDL_RenderClear(m_GameWindow.getRenderer());
    m_GameWorld.update();
    m_GameWorld.draw(m_GameWindow.getRenderer());
}

void Game::MenuLoop(){
    m_GameState = GAME;
}

bool Game::isQuit(){
    return m_Quit;
}

GameWindow Game::getWindow(){
    return m_GameWindow;
}

World Game::getWorld(){
    return m_GameWorld;
}

GameState Game::getGameState(){
    return m_GameState;
}

void Game::quit(){
    if(m_Quit){
        m_Quit = false;
    } else {
        m_Quit = true;
    }
}
