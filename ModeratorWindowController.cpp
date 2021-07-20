/************************************************//**
 * \file    ModeratorWindow.cpp
 * \brief   Here are defined all methods from Button class
***************************************************/

/**************************************************/
// Libraries

#include <iostream>
#include <SFML/Graphics.hpp>

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
    Sprite sprite;
    MainMenuView mainMenu = MainMenuView(&this->window, 0, 0, this->height, this->width);
    float i = 0;

    while (this->window.isOpen())
    {
        Event event;
        while (this->window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                this->window.close();
        }


        this->texture.clear();
        mainMenu.draw(texture);
        sprite.setTexture(this->texture.getTexture());

        this->window.clear();
        this->window.draw(sprite);
        this->window.display();
    }
};
