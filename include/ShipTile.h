#ifndef SHIPTILE_H
#define SHIPTILE_H

#include "Texture.h"

using namespace std;

enum Tile_type {
	Med_Bay,
	Barracks,
	Mess_Hall,
	Storage,
	Engineering,
	Corridor,
	Floor_Change,
	Tile_type_count
	};

class ShipTile {
public:
	ShipTile(Tile_type tclass);
	ShipTile(Tile_type tclass, int xPos, int yPos);
	ShipTile(Texture* texture, Tile_type tclass, int x, int y);

	int get_posX();
	int get_posY();

	void set_posX(int x);
	void set_posY(int y);

	void get_tile_class(char tile_marker);

	void draw(SDL_Renderer* renderer);
    
    private:
	int posX, posY;
	Tile_type tile_class;
    double hull_str;
	//#I agree, this should not be part of a tile class. Leave the count
	// to the vector in ship.
	//int tile_count; different class? focus on single tile for this class?
	Texture * c_Texture;
};

#endif