#ifndef CREW_H
#define CREW_H

#include <vector>
#include <queue>

#include "../include/Hand.h"
#include "../include/Camera.h"

using namespace std;

class Crew{
    public:
    Crew();
    ~Crew();

    bool addHand(Hand newHand);
    bool removeHand(Hand newHand);

    void draw(SDL_Renderer* renderer, Camera* cam);

    int getMaxCrew();
    int getCurrentCrewCount();

    //TODO: Figure out what the crew does... Maybe pathfinding checks? Job queue? TBD
    private:
    int m_MaxCrew;
    int m_CurrentCrewCount;
    vector<Hand> m_AllHands;
    //queue<Job> m_JobQ; //Queue for all jobs? maybe separate by department? Thread per department?
};

#endif