/************************************************//**
 * \file    ModeratorWindow.h
***************************************************/

#pragma once

/**************************************************/
// Libraries

#include "Window.h"

/**************************************************/
/**
 * ModeratorWindow class
 * This is an abstract class that is going be inherited by all windows.
 */
class ModeratorWindow : public Window
{
    private:

    protected:
        /********************/
        // Variables

        /********************/
        // Methods

        /**
         * \brief Creates the window's background, etc, but doesn`t show it until render.
         */
        virtual void draw() = 0;

    public:
        /********************/
        // Constructor

        /**
         * ModeratorWindow Constructor.
         *
         * \param width The desired width for the window.
         * \param height The desired height for the window.
         */
        ModeratorWindow(int width, int height);

        /********************/
        // Getters and setters methods


        /********************/
        // Methods

        /**
         * \brief Prints the button on screen.
         */
        virtual void render() = 0;
};
