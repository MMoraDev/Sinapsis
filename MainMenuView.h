/************************************************//**
 * \file    MainMenuView.h
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
 * MainMenuView class
 */
class MainMenuView : public UIElement
{
    private:

    protected:
        /********************/
        // Variables

        Image 
            logo,
            bg;
        map<string, vector<string>>
            options;

        /********************/
        // Methods

    public:
        /********************/
        // Constructor

        MainMenuView(RenderWindow* parent, int x, int y, int height, int width);

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
