/************************************************//**
 * \file    TextField.h
***************************************************/

#pragma once

/**************************************************/
// Libraries

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Settings.h"
#include "UIElement.h"

/**************************************************/
// Namespaces

using namespace std;
using namespace sf;

/**************************************************/
/**
 * WrappableText class
 */
class TextField : public WrappableText
{
    private:

    protected:
        /********************/
        // Variables

        /********************/
        // Methods

    public:

        /********************/
        // Constructor

        /**
         * WrappableText Constructor.
         *
         * \param x The x coordinate.
         * \param y The y coordinate.
         * \param height The desired height for the element.
         * \param width The desired width for the element.
         * \param text The text that will be printed on screen
         * \param padding The inner-margin
         * \param style (Optional) This will change the font weight and size
         * \param alignment (Optional) This will change the text alignment
         * \param fontColor (Optional) The color of the text
         * \param bgColor (Optional) Color of the background
         * \param borderRadius (Optional) Corner's radious
         */
        TextField(RenderWindow* parent, int x, int y, int height, int width, string text, Vector2f padding, Style style = Style::BODY, TextAlign alignment = TextAlign::LEFT, Color fontColor = Color::Black, Color bgColor = Color::Transparent, float borderRadius = 0);

        /********************/
        // Getters and setters methods

        /********************/
        // Methods

        /**
         * \brief Prints the ui on the canvas (doesn't show it on screen).
         */
        void initDrawables();

};


