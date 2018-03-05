#ifndef CAMERA_H
#define CAMERA_H

#include "GameWindow.h"

class Camera{
    public:
    Camera();
    Camera(int posX, int posY);
    ~Camera();

    void update();

    int getCamPosX();
    int getCamPosY();

    void setCamPosX(int posX);
    void setCamPosY(int posY);

    void moveCamera(int moveOnX, int moveOnY);

    private:
    double m_CamVelX;
    double m_CamVelY;

    double m_VelCap;

    int m_CamPosX;
    int m_CamPosY;
    GameWindow* m_GameWindow;
};

#endif