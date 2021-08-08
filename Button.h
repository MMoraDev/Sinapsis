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
        String text;
        Color
            fontColor,
            bgColor,
            onHoverBgColor;

        /********************/
        // Methods

    public:
        /********************/
        // Constructor

        Button(RenderWindow* parent, int x, int y, int height, int width, Image bg, Image onHoverBg, int opacity = 255, bool isVisible = true);

        Button(RenderWindow* parent, int x, int y, int height, int width, string text, Color font, Color bg, Color onHoverBg, bool isVisible = true);

        /********************/
        // Getters and setters methods

        int getOpacity();
        void setOpacity(int opacity);

        string getText();
        void setText(string text);

        /********************/
        // Methods

        void initDrawables();

        bool isClicked();
};
