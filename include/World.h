#ifndef WORLD_H
#define WORLD_H

#include <map>

#include "../include/Texture.h"
#include "../include/Hand.h"
#include "../include/Crew.h"
#include "../include/Ship.h"

class World{
    public:
    World();
    ~World();

    bool loadMedia(SDL_Renderer* renderer);

    void createCrew();

    void draw(SDL_Renderer* renderer);

    void update();

    void updateBackground();

    private:
    Ship m_Ship;
    Crew m_Crew;
    map<HandOccupation, Texture*> m_HandTextureMap;

};

#endif