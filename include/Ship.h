#ifndef SHIP_H
#define SHIP_H

#include <vector>

#include "../include/Vector2.h"
#include "../include/Texture.h"
#include "../include/ShipTile.h"
#include "../include/Camera.h"

using namespace std;

class Ship{
    public:
    Ship();
    ~Ship();

    void addTile(ShipTile tile);

    void draw(SDL_Renderer* renderer, Camera* cam);

    //Will probably have a bunch of other member methods that have to do with malfunctions, damage, 
    // etc.

    int getHull();
	void updateShip();

    private:
    int m_Hull;
    vector<ShipTile> m_ShipTiles;
};

#endif