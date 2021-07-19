/************************************************//**
 * \file    UIElement.h
***************************************************/

#pragma once

/**************************************************/
// Libraries

#include <SFML/Graphics.hpp>

/**************************************************/
// Namespaces

using namespace sf;

/**************************************************/
/**
 * UIElement class
 * This is an abstract class that is going be inherited by all classes that need to print on screen.
 */
class UIElement
{
    private:

    protected:
        /********************/
        // Variables

        int
            height = 0,
            width = 0,
            x = 0,
            y = 0;

        /********************/
        // Methods

    public:
        /********************/
        /**
         * Button Constructor.
         *
         * \param x The x coordinate.
         * \param y The y coordinate.
         * \param height The desired height for the element.
         * \param width The desired width for the element.
         */
        UIElement(int x, int y, int height, int width);

        /********************/
        // Getters and setters methods

        int getHeight();
        void setHeight(int height);

        int getWidth();
        void setWidth(int width);

        int getX();
        void setX(int x);

        int getY();
        void setY(int y);

        /********************/
        // Methods

        /**
         * \brief Prints the ui on the canvas (doesn't show it on screen).
         * 
         * \param canvas
         */
        virtual void draw(RenderTexture& canvas) = 0;
};
