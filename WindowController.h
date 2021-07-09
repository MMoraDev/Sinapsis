/************************************************//**
 * \file    WindowController.h
***************************************************/

#pragma once

/**************************************************/
// Libraries

#include <SFML/Graphics.hpp>

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
        int
            width = 0,
            height = 0;

        /********************/
        // Methods

        /**
         * \brief Creates the window's background, etc, but doesn`t show it until render.
         */
        virtual void draw() = 0;

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
};
