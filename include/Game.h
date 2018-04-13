#ifndef GAME_H
#define GAME_H

#include "../include/GameWindow.h"
#include "../include/World.h"

enum GameState { START_MENU, GAME, GAME_MENU, STATE_COUNT, INVAL_STATE};

class Game{
    public:
    Game();
    ~Game();

    void run();

    void close();

    void GameLoop();

    void MenuLoop();

    bool isQuit();
    GameWindow getWindow();
    World getWorld();
    GameState getGameState();

    void quit();

    private:
    bool m_Quit;
    //Once EventHandler is done...
    GameState m_GameState;
    GameWindow m_GameWindow;
    World m_GameWorld;

};

#endif