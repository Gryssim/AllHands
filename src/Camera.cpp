#include "../include/Camera.h"
#include <cmath>

using namespace std;

Camera::Camera(){
    m_VelCap = 5.0;
    m_CamPosX = 0;
    m_CamPosY = 0;
    m_CamVelX = 0;
    m_CamVelY = 0;
}

Camera::Camera(int posX, int posY){
    m_VelCap = 5.0;
    m_CamPosX = posX;
    m_CamPosY = posY;
    m_CamVelX = 0;
    m_CamVelY = 0;    
}

Camera::~Camera(){

}


void Camera::update(){
    if((m_CamPosX + m_CamVelX >= 0) && (m_CamPosY + m_CamVelY >= 0)
    && (m_CamPosX + m_CamVelX < 800 * 4) && (m_CamPosY + m_CamVelY < 600 * 4)){
        m_CamPosX += m_CamVelX;
        m_CamPosY += m_CamVelY;
    }
    if(m_CamVelX > 0){
        m_CamVelX -= 1;
    }
    if(m_CamVelX < 0){
        m_CamVelX += 1;
    }
    if(m_CamVelY > 0){
        m_CamVelY -= 1;
    }
    if(m_CamVelY < 0){
        m_CamVelY += 1;
    }
}

int Camera::getCamPosX(){
    return m_CamPosX;
}

int Camera::getCamPosY(){
    return m_CamPosY;
}

void Camera::setCamPosX(int posX){
    m_CamPosX = posX;
}

void Camera::setCamPosY(int posY){
    m_CamPosY = posY;
}

void Camera::moveCamera(int moveOnX, int moveOnY){
    //Update camera velocity based on input

    //If moveOnX > 0 increment m_CamVelX towards cap
    if(moveOnX > 0){
        if(m_CamVelX <= m_VelCap)
            m_CamVelX++;
    }
    //else if moveOnX < 0 decrement m_CamVelX towards cap using abs val
    if(moveOnX < 0){
        if(abs(m_CamVelX) <= m_VelCap)
            m_CamVelX--;
    }
    //if moveOnY > 0 increment m_CamVelY towards cap
    if(moveOnY > 0){
        if(m_CamVelY <= m_VelCap)
            m_CamVelY++;
    }
    //else if moveOnY < 0 decrement m_CamVelY towards cap using abs val
    if(moveOnY < 0){
        if(abs(m_CamVelY) <= m_VelCap)
            m_CamVelY--;
    }

    printf("VelX : %f.0    VelY : %f.0\n", m_CamVelX, m_CamVelY);
    printf("CamX : %i      CamY : %i\n", m_CamPosX, m_CamPosY);
}