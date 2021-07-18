/************************************************//**
 * \file    MainController.cpp
 * \brief   Here are defined all methods from MainController class
***************************************************/

/**************************************************/
// Libraries

#include <iostream>
#include <SFML/Graphics.hpp>

#include "MainController.h"
#include "ModeratorWindowController.h"


/**************************************************/
// Namespaces

using namespace sf;
using namespace std;

/**************************************************/
// Public

/*****************************/
// Constructor

MainController::MainController()
{
    this->currentState = State::MAIN_MENU;
};

/*****************************/
// Methods

void MainController::run()
{
    // Variables
    ModeratorWindowController mmoderatorWindow;
    Thread moderatorWindowThread(&ModeratorWindowController::run, &mmoderatorWindow);

    // Launch threads
    moderatorWindowThread.launch();
};

void MainController::setState(State newState)
{
    this->currentState = newState;
};
