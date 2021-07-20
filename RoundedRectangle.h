/************************************************//**
 * \file    RoundedRectangle.h
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
class RoundedRectangle : public UIElement
{
    private:

    protected:
        /********************/
        // Constants
        int
            POINTS = 10;

        /********************/
        // Variables
        float
            radius,
            outline;
        Color
            fillColor,
            outlineColor;

        /********************/
        // Methods

    public:
        /********************/
        // Constructor

        /**
         * RoundedRectangle Constructor.
         *
         * \param parent The pointer of the window that contains the element.
         * \param x The x coordinate.
         * \param y The y coordinate.
         * \param height The desired height for the element.
         * \param width The desired width for the element.
         * \param radius The radius for the rounded corners
         * \param fillColor Color of the inner rectangle
         * \param outline (Optional) Thickness of the border
         * \param outlineColor (Optional) Color of the border
         */
        RoundedRectangle(Window* parent, int x, int y, int height, int width, float radius, const Color& fillColor, float outline = 0.f, const Color& outlineColor = Color::Transparent);

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
