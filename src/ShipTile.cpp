#include "../include/ShipTile.h"

using namespace std;

ShipTile::ShipTile(Tile_type tclass)
{
    posX = 0;
    posY = 0;
    tile_class = tclass;
}

ShipTile::ShipTile(Tile_type tclass, int floor, int xPos, int yPos)
{
    m_Floor = floor;
    posX = xPos;
    posY = yPos;
    tile_class = tclass;
}

ShipTile::ShipTile(Texture* texture, Tile_type tclass, int x, int y)
{
    m_Texture = texture;
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

int ShipTile::get_floor()
{
    return m_Floor;
}


void ShipTile::set_posX(int x)
{
    posX = x;
}
void ShipTile::set_posY(int y)
{
    posY = y;
}
void ShipTile::set_floor(int floorNum)
{
    m_Floor = floorNum;
}


void ShipTile::get_tile_class(char tile_marker)
{
    char x = tile_marker;
    
    if (x == '#')
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
    else if (x == 'B')
    {
        tile_class = Bridge;
    }
    else
    {
        printf("Unreconized tile at %c", tile_marker);
    }
}

Tile_type ShipTile::get_marker_class(char tile_marker)
{
    char x = tile_marker;
    Tile_type retType;
    if (x == '#')
    {
        retType = Wall;
    }
    else if (x == 'M')
    {
        retType = Med_Bay;
    }
    else if (x == 'B')
    {
        retType = Barracks;
    }
    else if (x == 'C')//Mess Hall
    {
        retType = Mess_Hall;
    }
    else if (x == 'S')
    {
        retType = Storage;
    }
    else if (x == 'E')
    {
        retType = Engineering;
    }
    else if (x == 'F')
    {
        retType = Floor_Change;
    }
    else if (x == 'B')
    {
        retType = Bridge;
    }
    else if (x == 'H')
    {
        retType = Hall;
    }
    else
    {
        printf("Unreconized tile at %c", tile_marker);
    }
    return retType;
}

SDL_Color ShipTile::get_tile_color(Tile_type tile)
{
    SDL_Color retColor;
    retColor.a = 255;
    if (tile == Wall)
    {
        retColor.r = 0;
        retColor.g = 0;
        retColor.b = 0;
    }
    else if (tile == Med_Bay)
    {
        retColor.r = 255;
        retColor.g = 255;
        retColor.b = 255;
    }
    else if (tile == Barracks)
    {
        retColor.r = 0;
        retColor.g = 255;
        retColor.b = 0;
    }
    else if (tile == Mess_Hall)//Mess Hall
    {
        retColor.r = 126;
        retColor.g = 126;
        retColor.b = 126;
    }
    else if (tile == Storage)
    {
        retColor.r = 50;
        retColor.g = 50;
        retColor.b = 50;
    }
    else if (tile == Engineering)
    {
        retColor.r = 255;
        retColor.g = 255;
        retColor.b = 0;
    }
    else if (tile == Floor_Change)
    {
        retColor.r = 25;
        retColor.g = 135;
        retColor.b = 40;
    }
    else if (tile == Bridge)
    {
        retColor.r = 255;
        retColor.g = 0;
        retColor.b = 0;
    }
    else if (tile == Hall)
    {
        retColor.r = 0;
        retColor.g = 0;
        retColor.b = 126;
    }
    else
    {
        printf("Unreconized tile at %i", tile);
    }

    return retColor;
}

void ShipTile::draw(SDL_Renderer* renderer, Camera* cam, int currentFloor)
{
    int x, y, w, h;
    x = posX - cam->getCamPosX();
    y = posY - cam->getCamPosY();
    w = 25;
    h = 25;
    /*
    if (m_Texture == NULL) {
        printf("ShipNull");
    }
    m_Texture->draw(renderer, posX - cam->getCamPosX(), posY - cam->getCamPosY());
    */
    //printf("TileFloor: %i \nC_Floor: %i\n", m_Floor, currentFloor);
    if(m_Floor == currentFloor){
        //Let's just draw a rectangle...
        SDL_Rect newRect = {x, y, w - 2, h - 2};
        SDL_Rect borderRect = {x - 1, y - 1, w, h};
        //printf("x: %i y: %i w: %i h: %i \n", x, y, w, h);
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderFillRect(renderer, &borderRect);
        SDL_Color drawColor = get_tile_color(tile_class);
        //printf("r:%i g:%i b:%i\n", drawColor.r, drawColor.g, drawColor.b);
        SDL_SetRenderDrawColor(renderer, drawColor.r, drawColor.g, drawColor.b, drawColor.a);


        if (SDL_RenderFillRect(renderer, &newRect) < 0)
            printf("Error: %s", SDL_GetError());
    }

}
