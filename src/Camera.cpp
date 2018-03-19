#include "../include/Camera.h"
#include <cmath>

using namespace std;

Camera::Camera(){
    stopMove();
    m_VelDecay = 0.5;
    m_VelCap = 7.0;
    m_CamPosX = 0;
    m_CamPosY = 0;
    m_CamVelX = 0;
    m_CamVelY = 0;
}

Camera::Camera(int posX, int posY){
    stopMove();
    m_VelDecay = 0.3;
    m_VelCap = 10.0;
    m_CamPosX = posX;
    m_CamPosY = posY;
    m_CamVelX = 0;
    m_CamVelY = 0;    
}

Camera::~Camera(){

}

void Camera::startMove(){
    if(!isMoving){
        isMoving = true;
    }
}

void Camera::stopMove(){
    if(isMoving){
        isMoving = false;
    }
}

void Camera::update(){
    if((m_CamPosX + m_CamVelX >= 0) && (m_CamPosX + m_CamVelX < 800 * 4)){
        m_CamPosX += m_CamVelX;
    }
    if((m_CamPosY + m_CamVelY >= 0) && (m_CamPosY + m_CamVelY < 600 * 4)){
        m_CamPosY += m_CamVelY;
    }
    if(!isMoving){
        if(m_CamVelX > 0){
            m_CamVelX -= m_VelDecay;
        }
        if(m_CamVelX < 0){
            m_CamVelX += m_VelDecay;
        }
        if(m_CamVelY > 0){
            m_CamVelY -= m_VelDecay;
        }
        if(m_CamVelY < 0){
            m_CamVelY += m_VelDecay;
        }
    }
}

int Camera::getCamPosX(){
    return m_CamPosX;
}

int Camera::getCamPosY(){
    return m_CamPosY;
}

double Camera::getCamVelX(){
    return m_CamVelX;
}

double Camera::getCamVelY(){
    return m_CamVelY;
}

void Camera::setCamPosX(int posX){
    m_CamPosX = posX;
}

void Camera::setCamPosY(int posY){
    m_CamPosY = posY;
}

void Camera::moveCamera(int moveOnX, int moveOnY){
    //Update camera velocity based on input
    startMove();
    //If moveOnX > 0 increment m_CamVelX towards cap
    if(moveOnX > 0){
        if(m_CamVelX <= m_VelCap)
            m_CamVelX = m_VelCap;
    }
    //else if moveOnX < 0 decrement m_CamVelX towards cap using abs val
    if(moveOnX < 0){
        if(abs(m_CamVelX) <= m_VelCap)
            m_CamVelX = -m_VelCap;
    }
    //if moveOnY > 0 increment m_CamVelY towards cap
    if(moveOnY > 0){
        if(m_CamVelY <= m_VelCap)
            m_CamVelY = m_VelCap;
    }
    //else if moveOnY < 0 decrement m_CamVelY towards cap using abs val
    if(moveOnY < 0){
        if(abs(m_CamVelY) <= m_VelCap)
            m_CamVelY = -m_VelCap;
    }

    //printf("VelX : %f.0    VelY : %f.0\n", m_CamVelX, m_CamVelY);
    //printf("CamX : %i      CamY : %i\n", m_CamPosX, m_CamPosY);
}