/************************************************//**
 * \file    WindowController.h
***************************************************/

#pragma once

/**************************************************/
// Libraries

#include <iostream>
#include <SFML/Graphics.hpp>

#include "MainController.h"

/**************************************************/
// Namespaces

using namespace sf;

/**************************************************/
/**
 * WindowController class
 * This is an abstract class that is going be inherited by all windows.
 */
class WindowController
{
    private:

    protected:
        /********************/
        // Variables

        RenderWindow
            window;
        RenderTexture
            texture;
        int
            width = 0,
            height = 0;
        MainController::State
            currentState;

        /********************/
        // Methods

    public:
        /********************/
        // Getters and setters methods

        int getWidth();
        void setWidth(int width);

        int getHeight();
        void setHeight(int height);

        /********************/
        // Methods

        /**
         * \brief This is going to be the method called by the threads.
         */
        virtual void run() = 0;

        /**
         * \brief This sets the state of the wndow.
         */
        void setState(MainController::State newState);
};
