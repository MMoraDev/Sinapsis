/************************************************//**
 * \file    SlideableMenu.h
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
 * SlideableMenu class
 */
class SlideableMenu : public UIElement
{
    private:

    protected:
        /********************/
        // Variables

        map<string, vector<string>> options;
        map<string, vector<string>>::iterator actualOption;
        vector<Image> arrowImages;
        
        /********************/
        // Methods

    public:
        /********************/
        // Constructor

        /**
         * SlideableMenu Constructor.
         *
         * \param parent The pointer of the window that contains the element.
         * \param parent The window that contains the element.
         * \param x The x coordinate.
         * \param y The y coordinate.
         * \param height The desired height for the element.
         * \param width The desired width for the element.
         */
        SlideableMenu(RenderWindow* parent, int x, int y, int height, int width, map<string, vector<string>> options);

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
