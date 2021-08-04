/************************************************//**
 * \file    SignUpView.h
***************************************************/

#pragma once

/**************************************************/
// Libraries

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "UIElement.h"

/**************************************************/
// Namespaces

using namespace std;
using namespace sf;

/**************************************************/
/**
 * SignUpView class
 */
class SignUpView : public UIElement
{
    private:

    protected:
        /********************/
        // Variables

        Texture
            * bg;

        /********************/
        // Methods

    public:
        /********************/
        // Constructor

        SignUpView(RenderWindow* parent, int x, int y, int height, int width);

        /********************/
        // Getters and setters methods

        /********************/
        // Methods

        /**
         * \brief Prints the ui on the canvas (doesn't show it on screen).
         */
        void initDrawables();
};
