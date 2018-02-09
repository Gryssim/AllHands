#ifndef HAND_H
#define HAND_H

//General class for a singular Hand/crewman.
#include <string>
#include "../include/Texture.h"

using namespace std;

enum HandOccupation { CAPTAIN, ENGINEER, RED_SHIRT, SECURITY, PILOT, OCCUPATION_COUNT } ;

class Hand{
    public:

    Hand(Texture* texture, HandOccupation job);
    Hand(Texture* texture, HandOccupation job, int xPos, int yPos);
    ~Hand();

    bool operator==(const Hand& rightHand) const;

    void draw(SDL_Renderer* renderer);

    int getId();

    Texture* getTexture();

    private:
    Texture* m_HandTexture;
    HandOccupation m_Job;
    int m_xPos, m_yPos;
    int m_Id;
};

#endif