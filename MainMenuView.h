/************************************************//**
 * \file    MainMenuView.h
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
 * MainMenuView class
 */
class MainMenuView : public UIElement
{
    private:

    protected:
        /********************/
        // Variables
        Image 
            logo;

        /********************/
        // Methods

    public:
        /********************/
        // Constructor

        using UIElement::UIElement;

        /********************/
        // Getters and setters methods

        /********************/
        // Methods

        /**
         * \brief Prints the ui on the canvas (doesn't show it on screen).
         *
         * \param canvas
         */
        void draw(RenderTexture& canvas);
};
