/************************************************//**
 * \file    UIElement.h
***************************************************/

#pragma once

/**************************************************/
// Libraries

#include <iostream>
#include <SFML/Graphics.hpp>

/**************************************************/
// Namespaces

using namespace std;
using namespace sf;

/**************************************************/
/**
 * UIElement class
 * This is an abstract class that is going be inherited by all classes that need to print on screen.
 */
class UIElement : public Drawable
{
    private:

    protected:
        /********************/
        // Variables

        RenderWindow*
            parent;
        RectangleShape
            bounds;
        int
            height = 0,
            width = 0,
            x = 0,
            y = 0;
        bool
            isClickeable,
            isMouseInside;
        map<string, Drawable*>
            drawables;

        /********************/
        // Methods

        void setCursor(Cursor::Type cursor = Cursor::Arrow);

    public:
        /********************/
        // Constructor

        /**
         * UIElement Constructor.
         *
         * \param parent The pointer of the window that contains the element.
         * \param x The x coordinate.
         * \param y The y coordinate.
         * \param height The desired height for the element.
         * \param width The desired width for the element.
         * \param isClickeable
         */
        UIElement(RenderWindow* parent, int x, int y, int height, int width, bool isClickeable = false);

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

        virtual void initDrawables() = 0;

        void draw(RenderTarget& target, RenderStates states) const;

        bool isMouseOver();
};
