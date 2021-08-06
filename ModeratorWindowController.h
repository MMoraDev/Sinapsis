/************************************************//**
 * \file    ModeratorWindowController.h
***************************************************/

#pragma once

/**************************************************/
// Libraries

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "UIElement.h"
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
        bool flag = true;
    
    public:
        /********************/
        // Constants

        const enum class State {
            MAIN_MENU,
            SIGN_UP,
            GAME,
            WINNER
        };

        /********************/
        // Methods

    protected:

        /********************/
        // Variables

        State actualState;
        UIElement *view;
        map<string, string> selectedOption;
        Music* music;
        map<string, vector<map<string, string>>> teams;

    public:
        /********************/
        // Constructor

        ModeratorWindowController(int height, int width);

        /********************/
        // Getters and setters methods

        State getActualState();
        void setActualState(State state);

        /********************/
        // Methods

        /**
         * \brief Prints the button on screen.
         */
        void run();
};
