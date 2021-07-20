/************************************************//**
 * \file    ModeratorWindowController.h
***************************************************/

#pragma once

/**************************************************/
// Libraries

#include <iostream>
#include <SFML/Graphics.hpp>

#include "WindowController.h"

/**************************************************/
// Namespaces

using namespace std;
using namespace sf;

/**************************************************/
/**
 * ModeratorWindowController class
 * This is an abstract class that is going be inherited by all windows.
 */
class ModeratorWindowController : public WindowController
{
    private:
        /********************/
        // Variables

        const enum class State {
            MAIN_MENU
        };

        /********************/
        // Methods

    protected:

    public:
        /********************/
        // Constructor

        ModeratorWindowController(int height, int width);

        /********************/
        // Getters and setters methods

        /********************/
        // Methods

        /**
         * \brief Prints the button on screen.
         */
        void run();
};
