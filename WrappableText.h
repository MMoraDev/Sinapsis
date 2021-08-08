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
            BODY,
            QUESTION
        };

        const enum class TextAlign {
            LEFT,
            CENTER,
            RIGHT
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

        string text;
        Style style;
        TextAlign alignment;
        Color
            fontColor,
            bgColor;
        Vector2f padding;
        float borderRadius;
        Text * uiText;
        bool 
            isUnderlined,
            isClickable;

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
         * \param isUnderlined (Optional)
         * \param borderRadius (Optional) Corner's radious
         * \param isClickable (Optional)
         * \param isVisible (Optional)
         */
        WrappableText(RenderWindow* parent, int x, int y, int height, int width, string text, Vector2f padding, Style style = Style::BODY, TextAlign alignment = TextAlign::LEFT, Color fontColor = Color::Black, Color bgColor = Color::Transparent, bool isUnderlined = false, float borderRadius = 0, bool isClickable = false, bool isVisible = true);

        /********************/
        // Getters and setters methods

        string getText();
        void setText(string text);

        /********************/
        // Methods

        /**
         * Adds blank spaces to de left to alignm text.
         * 
         * \param line
         */
        void addLeftSpaces(string& line);

        /**
         * \brief Prints the ui on the canvas (doesn't show it on screen).
         */
        void initDrawables();

        /**
         * Returns an UI Text object with the specified style.
         *
         * \param style
         */
        void setStyle(Style style);
};
