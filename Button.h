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
        void loop() override;

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
        Type type;
        bool isReleased;
        int opacity;

        /********************/
        // Methods

    public:
        /********************/
        // Constructor

        Button(RenderWindow* parent, int x, int y, int height, int width, Image bg, Image onHoverBg, int opacity = 255);

        /********************/
        // Getters and setters methods

        int getOpacity();
        void setOpacity(int opacity);

        /********************/
        // Methods

        void initDrawables();

        bool isClicked();
};
