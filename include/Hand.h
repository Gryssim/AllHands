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
    ~Hand();

    int getId();

    Texture* getTexture();

    private:
    Texture* m_HandTexture;
    HandOccupation m_Job;

    int m_Id;
};

#endif