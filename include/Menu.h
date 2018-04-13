#ifndef MENU_H
#define MENU_H

#include <vector>

#include "../include/Texture.h"
#include "../include/Button.h"

class Menu{
    public:
    Menu();
    ~Menu();

    void addButton(Button button);

    private:
    Texture* m_BackgroundTexture;
    vector<Button> m_ButtonList;

};



#endif