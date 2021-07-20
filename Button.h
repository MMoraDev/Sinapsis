/************************************************//**
 * \file    Button.h
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
 * Button class
 */
class Button : public UIElement
{
    private:

    public:
        /********************/
        // Constants

        const enum class Type {
            IMAGE,
            TEXT,
        };

    protected:
        /********************/
        // Variables

        Image
            bg,
            onHoverBg;
        Type
            type;

        /********************/
        // Methods

    public:
        /********************/
        // Constructor

        Button(Window* parent, int x, int y, int height, int width, Image bg, Image onHoverBg);

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
