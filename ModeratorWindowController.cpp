/************************************************//**
 * \file    ModeratorWindow.cpp
 * \brief   Here are defined all methods from Button class
***************************************************/

/**************************************************/
// Libraries

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "RoundedRectangle.h"

#include "MainMenuView.h"
#include "ModeratorWindowController.h"
#include "Settings.h"
#include "SignUpView.h"
#include "MainGameView.h"
#include "WinnerView.h"
#include "StorageController.h"

/**************************************************/
// Dev libraries
#ifdef _DEBUG
    #include "Console.h"
#endif

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

    this->music = new Music();
    this->fx = new Music();
    this->isMusicReady = false;

    this->music->setVolume(20);
    this->music->setLoop(true);
    this->fx->setVolume(20);
    this->fx->setLoop(false);

    this->setActualState(State::MAIN_MENU);
}

/*****************************/
// Getters and setters methods

ModeratorWindowController::State ModeratorWindowController::getActualState() { return this->actualState; };
void ModeratorWindowController::setActualState(ModeratorWindowController::State state)
{
    State prevState = this->actualState;
    this->actualState = state;

    switch (this->actualState)
    {
        case ModeratorWindowController::State::MAIN_MENU:
            this->view = new MainMenuView(&this->window, 0, 0, this->height, this->width);
            this->isMusicReady = false;
            this->setMusic("menu");
            break;
        case ModeratorWindowController::State::SIGN_UP:
            this->view = new SignUpView(&this->window, 0, 0, this->height, this->width);
            this->setMusic("menu");
            break;
        case ModeratorWindowController::State::GAME:
            this->view = new MainGameView(&this->window, 0, 0, this->height, this->width, this->teams, this->selectedOption["Modo de juego"]);
            this->isMusicReady = false;
            this->setMusic("game");
            break;
        case ModeratorWindowController::State::WINNER:
            this->view = new WinnerView(&this->window, 0, 0, this->height, this->width, this->winner);
            this->setMusic("game");
            break;
    }
};

void ModeratorWindowController::setMusic(string fileName)
{
    if (!this->isMusicReady)
    {
        if (!this->music->openFromFile("resources\\audio\\" + fileName + ".ogg"))
        {
            #ifdef _DEBUG
                        Console().debug("Error loading the audio", "There was an error loading game.ogg", __LINE__, __FILE__, Console::Message_Type::ERR);
            #endif
        }

        this->music->play();
        this->isMusicReady = true;
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
                this->setActualState(State::WINNER);
            }
        }
        else if (this->actualState == State::SIGN_UP)
        {
            if (static_cast<SignUpView*>(this->view)->getIsDone())
            {
                this->teams = static_cast<SignUpView*>(this->view)->getData();
                this->setActualState(State::GAME);
            }
        }
        else if (this->actualState == State::GAME)
        {
            if (static_cast<MainGameView*>(this->view)->getWinner() != "")
            {
                this->winner = static_cast<MainGameView*>(this->view)->getWinner();
                this->setActualState(State::WINNER);
            }
        }
        else if (this->actualState == State::WINNER)
        {
            if (static_cast<WinnerView*>(this->view)->getIsDone())
            {
                this->setActualState(State::MAIN_MENU);
            }
        }

        if (this->view->getPlayAudio().size() > 0) {
            if (this->fx->getStatus() == Music::Status::Stopped) {
                map<string, bool> i = this->view->getPlayAudio();

                this->fx->openFromFile("resources\\audio\\" + i.begin()->first + ".ogg");
                this->fx->play();
            }
        }

        this->window.clear();
        this->window.draw(*(this->view));
        this->window.display();
        sleep(milliseconds(10));
    }
};
