#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2{
    public:
    Vector2(int x, int y);
    ~Vector2();

    int getX();
    void setX(int x);

    int getY();
    void setY(int y);
    
    private:
    int m_X, m_Y;
};

#endif