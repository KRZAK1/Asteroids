#include "SFML/Graphics.hpp"
#include "obj.h"
#include <iostream>
#include "polozenie.h"
#include "ruch.h"
#include <vector>
#include <time.h>
#include "tex.h"

using namespace std;
using namespace sf;

#define W 800
#define H 600


void obj::render()
{
    RenderWindow window(sf::VideoMode(W, H), "Asteroids");
    window.setFramerateLimit(60);

    CircleShape troj(15.f, 3);
    ruch r;
    polozenie p;
    vector<CircleShape>ast;
    srand(time(NULL));
    Clock clock;

    troj.setFillColor(Color::Black);
    troj.setOutlineThickness(1.f);
    troj.setOutlineColor(Color::White);
    troj.setPosition(400, 250);
    troj.setOrigin(15, 15);

    tex text("Wynik:",30,600.f,15.f);
    tex koniec("Koniec!",30,(W/2)-30, (H/2)-30);
    while (!Keyboard::isKeyPressed(Keyboard::Enter))
    {
        window.clear(Color::Black);
        tex start("Sterowanie: strzalki", 30, (W / 2) - 130, (H / 2) - 30);

        tex start1("Omijaj asteroidy!", 30, (W / 2) - 100, (H / 2) );

        tex start2("Wcisnij enter aby kontynuowac", 30, (W / 2) - 200, (H / 2) + 30);

        window.draw(start.t);
        window.draw(start1.t);
        window.draw(start2.t);
        window.display();
    }
    while (window.isOpen())
    {
        Time time = clock.getElapsedTime();
        tex text2(to_string(int(time.asSeconds()*10)),30,700.f,15.f);

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
        }
              
        window.clear(Color::Black);

        window.draw(troj);

        Vector2f point(r.x,r.y);

        for (int i = 0; i <10; i++)
        {
            ast.push_back(CircleShape(40.f, 7));
            ast[i].setFillColor(Color::Black);
            ast[i].setOutlineThickness(1.f);
            ast[i].setOutlineColor(Color::White);
            ast[i].setOrigin(40, 40);

            window.draw(ast[i]);
            ast[i].move(rand() % (i-10) - 2 , rand() % 5 + (i-4));
            p.granica(ast[i]);
            ast[i].setPosition(p.x, p.y);
            FloatRect otherBox = ast[i].getGlobalBounds();           
            if (otherBox.contains(point))
            {
                while (!Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    window.clear(Color::Black);
                    tex esc("Wcisnij esc aby wyjsc z gry",30, (W / 2) - 150, (H / 2) + 30);
                    tex kon("Wcisnij space aby sprobowac jeszcze raz", 30, (W / 2) - 250, (H / 2) + 60);
                    if (Keyboard::isKeyPressed(Keyboard::Space))
                    {
                        window.close();
                        render();
                    }
                    window.draw(koniec.t);
                    window.draw(text.t);
                    window.draw(text2.t);
                    window.draw(esc.t);
                    window.draw(kon.t);
                    window.display();
                }
            }
        }    
        r.r(troj);
        troj.setPosition(r.x, r.y);
        troj.setRotation(r.ob);

        p.granica(troj);
        troj.setPosition(p.x, p.y);

        window.draw(text.t);
        window.draw(text2.t);
        cout << time.asSeconds() << endl;
        window.display();
    }
}