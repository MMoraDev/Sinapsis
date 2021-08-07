/************************************************//**
 * \file    ModeratorWindowController.h
***************************************************/

#pragma once

/**************************************************/
// Libraries

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "MainView.h"
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
        MainView *view;
        map<string, string> selectedOption;
        Music
            * music,
            * fx;
        map<string, vector<map<string, string>>> teams;
        bool isMusicReady;

    public:
        /********************/
        // Constructor

        ModeratorWindowController(int height, int width);

        /********************/
        // Getters and setters methods

        State getActualState();
        void setActualState(State state);

        void setMusic(string fileName);

        /********************/
        // Methods

        /**
         * \brief Prints the button on screen.
         */
        void run();
};
