#include "SFML/Graphics.hpp"
#include "polozenie.h"

using namespace std;
using namespace sf;

#define W 800
#define H 600


    void polozenie::granica(CircleShape a)
    {
        if (a.getPosition().x > W)
            a.setPosition(0, a.getPosition().y);
        if (a.getPosition().y > H)
            a.setPosition(a.getPosition().x, 0);
        if (a.getPosition().x < 0)
            a.setPosition(800, a.getPosition().y);
        if (a.getPosition().y < 0)
            a.setPosition(a.getPosition().x, 600);
        x = a.getPosition().x;
        y = a.getPosition().y;
    }
