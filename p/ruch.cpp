#include "SFML/Graphics.hpp"
#include "obj.h"
#include "ruch.h"

using namespace std;
using namespace sf;

#define W 800
#define H 600


void ruch::r(CircleShape troj)
{  
    v = rot.transformPoint(0, 4);
    //cout << v.x << endl << v.y << endl;
    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        troj.rotate(3);
        rot.rotate(3);
    }
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        troj.rotate(-3);
        rot.rotate(-3);
    }
    if (Keyboard::isKeyPressed(Keyboard::Down))
    {
        troj.move(v);
    }
    if (Keyboard::isKeyPressed(Keyboard::Up))
    {
        troj.move(-v);
    }

    x = troj.getPosition().x;
    y = troj.getPosition().y;
    ob = troj.getRotation();
}