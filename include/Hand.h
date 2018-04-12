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
	Hand(Texture* texture, HandOccupation job, int xPos, int yPos);
	//Destuctor
	~Hand();

	//Accessor's
		//Vector2 getXYPos();
    bool operator==(const Hand& rightHand) const;
    void draw(SDL_Renderer* renderer, Camera* cam);
    int getId();
	int getX();
    int getY();

    Texture* getTexture();
	///////////////////////////////////////////////////////////////
	//Levi
	int getExhaustion(), getHunger(), getDehydration(), getAsphixiation(), getExperience();
	string getOccupation(), getRank();
	void setOccupation(string occupation);
	void setRank(string rank);
	void setY(int y_pos);
	void setX(int x_pos);
	void setID(int ID);
	void setExhaustion(int exhaustion);
	void setHunger(int hunger);
	void setDehydration(int dehydration);
	void setAsphixiation(int asphixiation);
	void setExperience(int experience);
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
	int exhaustion, hunger, dehydration, asphixiation, experience;
	string occupation, rank;
	vector<SDL_Rect> box;
	int xVel, yVel;
	void shift_boxes();
	///////////////////////////////////////////////////////////////
};


string HandOccupationToString(HandOccupation job);

#endif