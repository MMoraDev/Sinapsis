/************************************************//**
 * \file    Button.h
***************************************************/

#pragma once

/**************************************************/
// Libraries

#include <SFML/Graphics.hpp>

#include "UIElement.h"

/**************************************************/
// Namespaces

using namespace sf;

/**************************************************/
/**
 * Button class
 */
class SlideableMenu : public UIElement
{
    private:

    protected:
        /********************/
        // Variables

        int
            width = 0,
            height = 0;

        /********************/
        // Methods

        /**
         * \brief Creates the button's background, etc, but doesn`t show it until render.
         */
        void draw();

    public:
        /********************/
        // Constructor

        /**
         * Button Constructor.
         *
         * \param width The desired width for the window.
         * \param height The desired height for the window.
         */
        SlideableMenu(int width, int height);

        /********************/
        // Getters and setters methods

        /********************/
        // Methods

        /**
         * \brief Prints the button on screen.
         */
        void render();
};
