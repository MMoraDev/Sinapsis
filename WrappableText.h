/************************************************//**
 * \file    WrappableText.h
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
class WrappableText : public UIElement
{
    private:

    public:
        /********************/
        // Varaibles

        static vector<Font*> fonts;
        static bool initialized;

        const enum class Style {
            TITLE,
            SUBTITLE,
            SCORE,
            BODY
        };

        const vector<string> FontWeight {
            "ExtraBold",
            "Black",
            "Medium",
            "Regular"
        };

    protected:
        /********************/
        // Variables

        string
            text;
        Style
            style;
        Color
            fontColor,
            bgColor;
        float
            padding,
            borderRadius;
        Text
            uiText;

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
         * \param fontColor (Optional) The color of the text
         * \param bgColor (Optional) Color of the background
         * \param borderRadius (Optional) Corner's radious
         */
        WrappableText(int x, int y, int height, int width, string text, float padding, Style style = Style::BODY, Color fontColor = APP_COLORS().BLACK, Color bgColor = Color::Transparent, float borderRadius = 0);

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

        /**
         * Returns an UI Text object with the specified style.
         *
         * \param style
         */
        void setStyle(Style style);
};
