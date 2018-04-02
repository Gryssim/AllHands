#ifndef HAND_H
#define HAND_H

//General class for a singular Hand/crewman.
#include "../include/Vector2.h"
#include "../include/Texture.h"
#include "../include/Camera.h"

using namespace std;

enum HandOccupation {
    CAPTAIN,
    ENGINEER,
    REDSHIRT,
    SECURITY,
    PILOT,
    OCCUPATION_COUNT,
    INVALID 
    };

class Hand{
    public:
		static const int HAND_VEL = 10; //Maximum axis velocity of the crew

		Hand(Texture* texture, HandOccupation job);
		Hand(Texture* texture, HandOccupation job, int xPos, int yPos, int Hand_Velocity);
		Hand(Texture* texture, HandOccupation job, Vector2 pos);
		~Hand();
		void move(); // Levi
		void updateMove();
		void draw(SDL_Renderer* renderer, Camera* cam);

		bool operator==(const Hand& rightHand) const;
		
		int getId();
		int getX();
		int getY();
		Texture* getTexture();
		Vector2 getXYPos();

    private:
		Texture* m_HandTexture;
		HandOccupation m_Job;
		int m_xPos, m_yPos;
		int m_VelX, m_VelY; // Levi
		int m_Id;
};

string HandOccupationToString(HandOccupation job);

#endif