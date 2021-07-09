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
#include "Settings.h"

/**************************************************/
// Namespaces

using namespace sf;
using namespace std;

/**************************************************/
// Public

/*****************************/
// Methods

void MainController::run() {
    // Varaibles
    ModeratorWindowController mmoderatorWindow;
    Thread moderatorWindowThread(&ModeratorWindowController::run, &mmoderatorWindow);

    // Launch threads
    moderatorWindowThread.launch();
}
