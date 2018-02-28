#include "../include/ShipTile.h"

using namespace std;

ShipTile::ShipTile(Tile_type tclass)
{
    posX = 0;
    posY = 0;
    tile_class = tclass;
}

ShipTile::ShipTile(Tile_type tclass, int xPos, int yPos)
{
    posX = xPos;
    posY = yPos;
    tile_class = tclass;
}

ShipTile::ShipTile(Texture* texture, Tile_type tclass, int x, int y)
{
    c_Texture = texture;
    tile_class = tclass;
    posX = x;
    posY = y;
}

int ShipTile::get_posX()
{
    return posX;
}

int ShipTile::get_posY()
{
    return posY;
}

void ShipTile::set_posX(int x)
{
    posX = x;
}
void ShipTile::set_posY(int y)
{
    posY = y;
}

void ShipTile::get_tile_class(char tile_marker)
{
    char x = tile_marker;
    if (x == '*')
    {
        //draw wall
    }
    else if (x == 'M')
    {
        tile_class = Med_Bay;
    }
    else if (x == 'B')
    {
        tile_class = Barracks;
    }
    else if (x == 'C')//Mess Hall
    {
        tile_class = Mess_Hall;
    }
    else if (x == 'S')
    {
        tile_class = Storage;
    }
    else if (x == 'E')
    {
        tile_class = Engineering;
    }
    else if (x == 'F')
    {
        tile_class = Floor_Change;
    }
    else
    {
        printf("Unreconized tile at %c", tile_marker);
    }
}

void ShipTile::draw(SDL_Renderer* renderer)
{
    if (c_Texture == NULL) {
        printf("ShipNull");
    }
    c_Texture->draw(renderer, posX, posY);
}
