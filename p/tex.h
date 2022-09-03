#pragma once
#include "obj.h"

class tex
{
protected:
    friend void obj::render();
    sf::Text t;
    sf::Font font;
      
    tex(std::string tx, int r, int px, int py)
    {
        font.loadFromFile("trench100.ttf");
        t.setFont(font);
        t.setString(tx);
        t.setCharacterSize(r);
        t.setPosition(px, py);
        t.setFillColor(sf::Color::White);
    }
};