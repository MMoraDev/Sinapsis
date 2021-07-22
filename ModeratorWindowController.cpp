/************************************************//**
 * \file    ModeratorWindow.cpp
 * \brief   Here are defined all methods from Button class
***************************************************/

/**************************************************/
// Libraries

#include <iostream>
#include <SFML/Graphics.hpp>

#include "RoundedRectangle.h"

#include "MainMenuView.h"
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

/**************************************************/
// Public

/*****************************/
// Constructor

ModeratorWindowController::ModeratorWindowController(int height, int width) : WindowController(height, width)
{
    // We sets the texture size and display it once (it doesn`t display anything, but we need it to avoid errors while drawing).
    this->texture.create(width, height);
    this->texture.display();
}

/*****************************/
// Methods

void ModeratorWindowController::run()
{
    this->window.create(VideoMode(this->width, this->height), APP_TITLE + " - Moderador");
    MainMenuView mainMenu = MainMenuView(&this->window, 0, 0, this->height, this->width);
    RoundedRectangle r = RoundedRectangle(&this->window, 50, 50, 100, 100, 10, APP_COLORS().PRIMARY);

    while (this->window.isOpen())
    {
        Event event;
        while (this->window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                this->window.close();
        }

        //this->window.clear();
        this->window.draw(mainMenu);
        //this->window.draw(r);
        this->window.display();
    }
};
