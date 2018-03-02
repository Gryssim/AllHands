#ifndef WORLD_H
#define WORLD_H

#include <map>

#include "../include/Texture.h"
#include "../include/Hand.h"
#include "../include/Crew.h"
#include "../include/Ship.h"
#include "../include/ShipTile.h"

const int MAX_STARS = 100;

struct backgroundStar{
    int posX, posY;
};

class World{
    public:
    World();
    ~World();

    bool loadMedia(SDL_Renderer* renderer);

    void createShip();

    void createCrew();

    void draw(SDL_Renderer* renderer);
    void drawStar(SDL_Renderer* renderer, backgroundStar star, int scale);

    void update();

    void initBackground();
    void updateBackground();

    private:
    Ship m_Ship;
    Crew m_Crew;
    Texture* t_TestTileTexture;

    backgroundStar m_Stars[MAX_STARS];
    map<HandOccupation, Texture*> m_HandTextureMap;
    map<Tile_type, Texture*> m_TileTextureMap;

};

#endif