#include <algorithm>
#include "../include/Crew.h"

Crew::Crew(){

}

Crew::~Crew(){

}

bool Crew::addHand(Hand newHand){
    bool success = true;

    m_AllHands.push_back(newHand);

    if(success) m_CurrentCrewCount += 1;
    return success;
}

bool Crew::removeHand(Hand newHand){
    bool success = true;

    vector<Hand>::iterator position = std::find(m_AllHands.begin(), m_AllHands.end(), newHand);
    if(position != m_AllHands.end())
         m_AllHands.erase(position);
    else 
        success = false;
    if(success) m_CurrentCrewCount -= 1;

    return success;
}