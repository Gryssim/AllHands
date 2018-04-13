#ifndef HAND_H
#define HAND_H

//General class for a singular Hand/crewman.
#include "../include/Vector2.h"
#include "../include/Texture.h"
#include "../include/Camera.h"
//Levi
#include <vector>
#include <iostream>
#include <string>
///////////////////////////////////////////////////////////////

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

class Hand {
public:
	//Constructor (why are there multiple?)
		//Hand(Texture* texture, HandOccupation job);
		//Hand(Texture* texture, HandOccupation job, Vector2 pos);
	Hand(Texture* texture, HandOccupation job, int xPos, int yPos, int Id);//added int for ID
	//Destuctor
	~Hand();

	///////////////////////////////////////////////////////////////
	//Levi
	//Member Methods
	void updateHand();
	void displayStats();
	void checkHandStats();
	void sleep();
	void eat();
	void drink();
	void pass_out();
	void wander();
	//Accessor's
	///////////////////////////////////////////////////////////////
		//Vector2 getXYPos();
    bool operator==(const Hand& rightHand) const;
    void draw(SDL_Renderer* renderer, Camera* cam);
    int getId();
	int getX();
    int getY();
    Texture* getTexture();
	///////////////////////////////////////////////////////////////
	//Levi
	int getExhaustion() { return EXHAUSTION; } 
	int getHunger() { return HUNGER; }
	int getDehydration() { return DEHYDRATION; }
	int getAsphixiation() { return ASPHIXIATION; }
	int getExperience() { return EXPERIENCE; }
	int getxVel() { return xVel; }
	int getyVel() { return yVel; }
	string getOccupation() { return OCCUPATION; }
	string getRank() { return RANK; }

	void setOccupation(string occupation) { OCCUPATION = occupation; }
	void setRank(string rank) { RANK = rank; }
	void setY(int y_pos) { m_yPos = y_pos; }
	void setX(int x_pos) { m_xPos = x_pos; }
	void setXVel(int x_vel) { xVel = x_vel; }
	void setyVel(int y_vel) { yVel = y_vel; }
	void setID(int ID) { m_Id = ID; }
	void setExhaustion(int exhaustion) { EXHAUSTION = exhaustion; }
	void setHunger(int hunger) { HUNGER = hunger; }
	void setDehydration(int dehydration) { DEHYDRATION = dehydration; }
	void setAsphixiation(int asphixiation) { ASPHIXIATION = asphixiation; }
	void setExperience(int experience) { EXPERIENCE = experience; }
	void handle_input();
	void move(std::vector<SDL_Rect> &rects);
	vector<SDL_Rect> &get_rects();
	///////////////////////////////////////////////////////////////

    private:
    Texture* m_HandTexture;
    HandOccupation m_Job;
    int m_xPos, m_yPos;
	int m_Id;
	///////////////////////////////////////////////////////////////
	//Levi
	int	xVel, yVel, EXHAUSTION, HUNGER, DEHYDRATION,ASPHIXIATION, EXPERIENCE;
	string OCCUPATION, RANK;
	vector<SDL_Rect> box;
	void shift_boxes();
	///////////////////////////////////////////////////////////////
};


string HandOccupationToString(HandOccupation job);

#endif