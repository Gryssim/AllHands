#ifndef HAND_H
#define HAND_H

//General class for a singular Hand/crewman.
#include "../include/Vector2.h"
#include "../include/Texture.h"

using namespace std;

enum HandOccupation { CAPTAIN, ENGINEER, REDSHIRT, SECURITY, PILOT, OCCUPATION_COUNT, INVALID } ;

class Hand{
    public:

    Hand(Texture* texture, HandOccupation job);
    Hand(Texture* texture, HandOccupation job, int xPos, int yPos);
    Hand(Texture* texture, HandOccupation job, Vector2 pos);
    ~Hand();

    bool operator==(const Hand& rightHand) const;

    void draw(SDL_Renderer* renderer);

    int getId();

    Vector2 getXYPos();
    int getX();
    int getY();

    Texture* getTexture();

    private:
    Texture* m_HandTexture;
    HandOccupation m_Job;
    int m_xPos, m_yPos;
    int m_Id;
};


string HandOccupationToString(HandOccupation job);

#endif