#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>

using namespace std;

class GameWindow {
    public:
    GameWindow(int width, int height, string winTitle);
    ~GameWindow();

    bool init();

    void close();

    private:
    SDL_Window* m_Window;
    SDL_Renderer* m_Renderer;

    int m_WinHeight;
    int m_WinWidth;

    string m_WinTitle;
};