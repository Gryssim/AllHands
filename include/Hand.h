#ifndef HAND_H
#define HAND_H

//General class for a singular Hand/crewman.
#include "../include/Vector2.h"
#include "../include/Texture.h"
#include "../include/Camera.h"
//Levi
#include <vector>
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

class Hand{
    public:

    Hand(Texture* texture, HandOccupation job);
    Hand(Texture* texture, HandOccupation job, int xPos, int yPos);
    Hand(Texture* texture, HandOccupation job, Vector2 pos);
    ~Hand();

    bool operator==(const Hand& rightHand) const;

    void draw(SDL_Renderer* renderer, Camera* cam);

    int getId();

    Vector2 getXYPos();
    int getX();
    int getY();

    Texture* getTexture();
	///////////////////////////////////////////////////////////////
	//Levi
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
	vector<SDL_Rect> box;
	int xVel, yVel;
	void shift_boxes();
	///////////////////////////////////////////////////////////////
};


string HandOccupationToString(HandOccupation job);

#endif