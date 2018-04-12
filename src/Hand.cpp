#include "../include/Hand.h"
#include "../include/Texture.h"

///////////////////////////////////////////////////////////////
//Levi
#include <vector>
#include <string>

const int hand_WIDTH = 20;
const int hand_HEIGHT = 20;
SDL_Event event;
///////////////////////////////////////////////////////////////

Hand::Hand(Texture* texture, HandOccupation job){
    m_xPos = 0;
    m_yPos = 0;
    m_HandTexture = texture;
    m_Job = job;
}

Hand::Hand(Texture* texture, HandOccupation job, int xPos, int yPos){
    m_xPos = xPos;
    m_yPos = yPos;
    m_HandTexture = texture;
    m_Job = job;
	///////////////////////////////////////////////////////////////
	//Levi
	xVel = 0;
	yVel = 0;
	box.resize(11);
	box[0].w = 6;
	box[0].h = 1;
	box[1].w = 10;
	box[1].h = 1;
	box[2].w = 14;
	box[2].h = 1;
	box[3].w = 16;
	box[3].h = 2;
	box[4].w = 18;
	box[4].h = 2;
	box[5].w = 20;
	box[5].h = 6;
	box[6].w = 18;
	box[6].h = 2;
	box[7].w = 16;
	box[7].h = 2;
	box[8].w = 14;
	box[8].h = 1;
	box[9].w = 10;
	box[9].h = 1;
	box[10].w = 6;
	box[10].h = 1;
	shift_boxes();
}

Hand::Hand(Texture* texture, HandOccupation job, Vector2 pos){
    m_xPos = pos.getX();
    m_yPos = pos.getY();
    m_HandTexture = texture;
    m_Job = job;
}

Hand::~Hand(){

}

bool Hand::operator==(const Hand& rightHand) const{
    return this->m_Id == rightHand.m_Id;
}

void Hand::draw(SDL_Renderer* renderer, Camera* cam){
    //printf("Hand Pos: x - %i    y - %i\n", m_xPos, m_yPos);
    if(m_HandTexture == NULL){
        printf("HandNull");
    }
    m_HandTexture->draw(renderer, m_xPos - cam->getCamPosX(), m_yPos - cam->getCamPosY());
}

int Hand::getId(){
    return m_Id;
}

Vector2 Hand::getXYPos(){
    return Vector2(m_xPos, m_yPos);
}

int Hand::getX(){
    return m_xPos;
}

int Hand::getY(){
    return m_yPos;
}


Texture* Hand::getTexture(){
    return m_HandTexture;
}

string HandOccupationToString(HandOccupation job){
    string returnString = "";

    switch(job){
        case CAPTAIN:
            returnString = "captain";
            break;
        case ENGINEER:
            returnString = "engineer";
            break;
        case REDSHIRT:
            returnString = "redshirt";
            break;
        case SECURITY:
            returnString = "security";
            break;
        case PILOT:
            returnString = "pilot";
            break;
        default:
            returnString = "";
            break;
    }

    return returnString;
}
///////////////////////////////////////////////////////////////
//Levi
bool check_collision(std::vector<SDL_Rect> &A, std::vector<SDL_Rect> &B) {
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;
	for (int Abox = 0; Abox < A.size(); Abox++) {
		leftA = A[Abox].x;
		rightA = A[Abox].x + A[Abox].w;
		topA = A[Abox].y;
		bottomA = A[Abox].y + A[Abox].h;
		for (int Bbox = 0; Bbox < B.size(); Bbox++) {
			leftB = B[Bbox].x;
			rightB = B[Bbox].x + B[Bbox].w;
			topB = B[Bbox].y;
			bottomB = B[Bbox].y + B[Bbox].h;
			if (((bottomA <= topB) || (topA >= bottomB) || (rightA <= leftB) || (leftA >= rightB)) == false) {
				return true;
			}
		}
	}
	return false;
}

void Hand::shift_boxes() {
	int r = 0;
	for (int set = 0; set < box.size(); set++) {
		box[set].x = m_xPos + (hand_WIDTH - box[set].w) / 2;
		box[set].y = m_yPos + r;
		r += box[set].h;
	}
}

void Hand::handle_input() {
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_w: yVel -= 1; break;
		case SDLK_s: yVel += 1; break;
		case SDLK_a: xVel -= 1; break;
		case SDLK_d: xVel += 1; break;
		}
	}
	else if (event.type == SDL_KEYUP) {
		switch (event.key.keysym.sym) {
		case SDLK_w: yVel += 1; break;
		case SDLK_s: yVel -= 1; break;
		case SDLK_a: xVel += 1; break;
		case SDLK_d: xVel -= 1; break;
		}
	}
}

void Hand::move(std::vector<SDL_Rect> &rects) {
	m_xPos += xVel;
	shift_boxes();
	if ((m_xPos < 0) || (m_xPos + hand_WIDTH > 800/*SCREEN_WIDTH, instead of screen.. pass room?ship?*/) || (check_collision(box, rects))) {
		m_xPos -= xVel;
		shift_boxes();
	}
	m_yPos += yVel;
	shift_boxes();
	if ((m_yPos < 0) || (m_yPos + hand_HEIGHT > 600/*SCREEN_HEIGHT*/) || (check_collision(box, rects))) {
		m_yPos -= yVel;
		shift_boxes();
	}
}

std::vector<SDL_Rect> &Hand::get_rects() {
	return box;
}
/*
in main
Hand myhand(0, 0), otherobject0001(20, 20);

while (quit == false){
	while (SDL_PollEvent(&event)){
		myhand.handle_input();
	}
	//in running loop
	myhand.move(otherhand.get_rects());
	myhand.show();
	otherobject0001.show();
}
*/
///////////////////////////////////////////////////////////////