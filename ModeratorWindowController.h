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

using namespace sf;
using namespace std;

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

        /********************/
        // Methods

        /**
         * \brief Creates the window's background, etc, but doesn`t show it until render.
         */
        void draw();

    protected:

    public:
        /********************/
        // Getters and setters methods


        /********************/
        // Methods

        /**
         * \brief Prints the button on screen.
         */
        void run();
};
