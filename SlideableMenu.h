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

        float MAX_GAP = 25;

        /********************/
        // Variables

        map<string, vector<string>> options;
        map<string, vector<string>>::iterator actualOption;
        vector<Image> arrowImages;
        float gap;
        
        /********************/
        // Methods

    public:
        /********************/
        // Constants

        const enum class Direction {
            LEFT,
            RIGHT,
        };

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

        void changeOption(map<string, vector<string>>::iterator option, Direction dirrection = Direction::LEFT);

        /**
         * \brief Prints the ui on the canvas (doesn't show it on screen).
         */
        void initDrawables();
};
