/************************************************//**
 * \file    ModeratorWindow.cpp
 * \brief   Here are defined all methods from Button class
***************************************************/

/**************************************************/
// Libraries

#include <iostream>
#include <SFML/Graphics.hpp>

#include "ModeratorWindowController.h"
#include "Settings.h"

/**************************************************/
// Namespaces

using namespace sf;
using namespace std;

/**************************************************/
// Private

/*****************************/
// Methods

void ModeratorWindowController::draw() {

};

/**************************************************/
// Public

/*****************************/
// Methods

void ModeratorWindowController::run()
{
    window.create(VideoMode(700, 500), APP_TITLE + " - Moderador");
    CircleShape shape(100.f);
    float i = 0;
    shape.setFillColor(Color::Green);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        shape.setPosition(i++, 0);

        window.clear();
        window.draw(shape);
        window.display();
    }
};