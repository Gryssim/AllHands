#include "../include/Vector2.h"

Vector2::Vector2(int x, int y){
    m_X = x;
    m_Y = y;
}

Vector2::~Vector2(){

}

int Vector2::getX(){
    return m_X;
}
void Vector2::setX(int x){
    m_X = x;
}

int Vector2::getY(){
    return m_Y;
}

void Vector2::setY(int y){
    m_Y = y;
}