/************************************************//**
 * \file    MainController.h
***************************************************/

#pragma once

/**************************************************/
// Libraries

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

/**************************************************/
// Namespaces

using namespace sf;
using namespace std;

/**************************************************/
/**
 * MainController class
 */
class MainController
{
    private:

    public:
        /********************/
        // Constants

        const enum class State {
            MAIN_MENU
        };


    protected:
        /********************/
        // Variables

        State
            currentState;

        /********************/
        // Methods

    public:
        /********************/
        // Constructor

        MainController();

        /********************/
        // Getters and setters methods


        /********************/
        // Methods

        /**
         * \brief This is the function that main will call.
         */
        void run();

        /**
         * Sets the state of the game.
         *
         * \param newState
         */
        void setState(State newState);
};
