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
        /********************/
        // Methods

        void draw(RenderTarget& target, RenderStates states) const override;

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

        Texture
            *bg,
            *onHoverBg;
        Type
            type;

        /********************/
        // Methods

    public:
        /********************/
        // Constructor

        Button(RenderWindow* parent, int x, int y, int height, int width, Image bg, Image onHoverBg);

        /********************/
        // Getters and setters methods

        /********************/
        // Methods

        void initDrawables();
};
