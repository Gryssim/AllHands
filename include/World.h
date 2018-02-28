#ifndef WORLD_H
#define WORLD_H

#include <map>

#include "../include/Texture.h"
#include "../include/Hand.h"
#include "../include/Crew.h"
#include "../include/Ship.h"
#include "../include/ShipTile.h"

class World{
    public:
    World();
    ~World();

    bool loadMedia(SDL_Renderer* renderer);

    void createShip();

    void createCrew();

    void draw(SDL_Renderer* renderer);

    void update();

    void updateBackground();

    private:
    Ship m_Ship;
    Crew m_Crew;
    Texture* t_TestTileTexture;

    map<HandOccupation, Texture*> m_HandTextureMap;
    map<Tile_type, Texture*> m_TileTextureMap;

};

#endif