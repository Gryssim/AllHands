#include <algorithm>
#include "../include/Crew.h"

Crew::Crew(){
    m_MaxCrew = 20; // Not Final
    m_CurrentCrewCount = 0;
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

void Crew::draw(SDL_Renderer* renderer, Camera* cam){
    for(int i = 0; i < m_AllHands.size(); ++i){
        if(((m_AllHands[i].getX() < cam->getCamPosX() + 800 + 25) &&
            (m_AllHands[i].getX() > cam->getCamPosX() - 25)) &&
            ((m_AllHands[i].getY() < cam->getCamPosY() + 600 + 25) &&
            (m_AllHands[i].getY() > cam->getCamPosY() - 25))){        
                m_AllHands[i].draw(renderer, cam);
            }
    }
}

int Crew::getMaxCrew(){
    return m_MaxCrew;
}

int Crew::getCurrentCrewCount(){
    return m_CurrentCrewCount;
}

void Crew::updateCrew() {
	m_Hand.updateMove();
}