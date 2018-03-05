#ifndef CAMERA_H
#define CAMERA_H

#include "GameWindow.h"

class Camera{
    public:
    Camera();
    Camera(int posX, int posY);
    ~Camera();

    void update();

    void startMove();
    void stopMove();

    int getCamPosX();
    int getCamPosY();
    double getCamVelX();
    double getCamVelY();

    void setCamPosX(int posX);
    void setCamPosY(int posY);

    void moveCamera(int moveOnX, int moveOnY);

    private:
    bool isMoving;

    double m_CamVelX;
    double m_CamVelY;
    
    double m_VelDecay;

    double m_VelCap;

    int m_CamPosX;
    int m_CamPosY;
    GameWindow* m_GameWindow;
};

#endif