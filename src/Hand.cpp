#include "../include/Hand.h"
#include "../include/Texture.h"

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
}

Hand::Hand(Texture* texture, HandOccupation job, Vector2 pos){
    m_xPos = pos.getX();
    m_yPos = pos.getY();
    m_HandTexture = texture;
    m_Job = job;
}

Hand::Hand(Texture* texture, HandOccupation job, int Hand_Vel) { // Levi
	m_xPos = 0;
	m_yPos = 0;

	m_VelX = 0;
	m_VelY = 0;
}

Hand::~Hand(){

}

void Hand::move() // Levi
{
	//Move the hand left or right
	m_xPos += m_VelX;

	//If the hand went too far to the left or right
	if ((m_xPos < 0) || (m_xPos + 20 > 800)) // Hand Width 20 & Tile (world) Width 800
	{
		//Move back
		m_xPos -= m_VelX;
	}
	//Move the Hand up or down
	m_yPos += m_VelY;

	//If the Hand went too far up or down
	if ((m_yPos < 0) || (m_yPos + 20 > 600)) // Hand Height 20 & Tile(world) Height 600
	{
		//Move back
		m_yPos -= m_VelY;
	}
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
	move(); // Levi
}

void Hand::handleMovement() // Levi
{
	int x = rand() % 4;
	switch (x)
	{
	case 0: m_VelY -= HAND_VEL; break;
	case 1: m_VelY += HAND_VEL; break;
	case 2: m_VelX -= HAND_VEL; break;
	case 3: m_VelX += HAND_VEL; break;
	}
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
