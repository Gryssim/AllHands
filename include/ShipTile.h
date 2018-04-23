#ifndef SHIPTILE_H
#define SHIPTILE_H

#include "Texture.h"
#include "../include/Camera.h"

using namespace std;

enum Tile_type {
	Bridge,
	Med_Bay,
	Barracks,
	Mess_Hall,
	Storage,
	Engineering,
	Corridor,
	Floor_Change,
	Wall,
	Hall,
	Tile_type_count
	};

class ShipTile {
public:
	ShipTile(Tile_type tclass);
	ShipTile(Tile_type tclass, int floor, int xPos, int yPos);
	ShipTile(Texture* texture, Tile_type tclass, int x, int y);

	int get_posX();
	int get_posY();
	int get_floor();

	void set_posX(int x);
	void set_posY(int y);
	void set_floor(int floorNum);

	void get_tile_class(char tile_marker);

	static Tile_type get_marker_class(char tile_marker);
	static SDL_Color get_tile_color(Tile_type tile);

	void draw(SDL_Renderer* renderer, Camera* cam, int currentFloor);
    
    private:
	int posX, posY, m_Floor;
	Tile_type tile_class;
    double hull_str;
	Texture * m_Texture;
	//Equipment m_EquipOnTile
};

#endif