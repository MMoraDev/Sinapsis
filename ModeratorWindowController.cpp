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
#include "SignUpView.h"
#include "MainGameView.h"

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
    this->setActualState(State::MAIN_MENU);
}

/*****************************/
// Getters and setters methods

ModeratorWindowController::State ModeratorWindowController::getActualState() { return this->actualState; };
void ModeratorWindowController::setActualState(ModeratorWindowController::State state)
{
    this->actualState = state;

    switch (this->actualState)
    {
        case ModeratorWindowController::State::MAIN_MENU:
            this->view = new MainMenuView(&this->window, 0, 0, this->height, this->width);;
            break;
        case ModeratorWindowController::State::SIGN_UP:
            this->view = new SignUpView(&this->window, 0, 0, this->height, this->width);;
            break;
        case ModeratorWindowController::State::GAME:
            this->view = new MainGameView(&this->window, 0, 0, this->height, this->width);;
            break;
    }
};

/*****************************/
// Methods

void ModeratorWindowController::run()
{
    this->window.create(VideoMode(this->width, this->height), APP_TITLE + " - Moderador");
    this->window.setVerticalSyncEnabled(true);

    while (this->window.isOpen())
    {
        Event event;
        String input;
        while (this->window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                this->window.close();

            if (event.type == Event::TextEntered)
            {
                input = event.text.unicode;
                static_cast<SignUpView*>(this->view)->changeSelectedTextField(input);
            }
        }

        if (this->actualState == State::MAIN_MENU)
        {
            this->selectedOption = static_cast<MainMenuView*>(this->view)->getSelectedOption();
            if (this->selectedOption.size() > 0)
            {
                this->setActualState(State::GAME);
            }
        }
        else if (this->actualState == State::SIGN_UP)
        {
        }

        this->window.clear();
        this->window.draw(*(this->view));
        this->window.display();
        sleep(milliseconds(10));
    }
};
