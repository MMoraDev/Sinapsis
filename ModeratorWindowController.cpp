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

/**************************************************/
// Constructor

ModeratorWindowController::ModeratorWindowController()
{
    window.create(VideoMode(700, 500), APP_TITLE + " - Moderador");
};

/*****************************/
// Methods

void ModeratorWindowController::run()
{
    CircleShape shape(100.f);
    shape.setFillColor(Color::Green);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
};