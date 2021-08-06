/************************************************//**
 * \file    MainGameView.h
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
class MainGameView : public UIElement
{
    private:
        /********************/
        // Variables
        int
            scores[2] = {0, 0};
        map<string, vector<map<string, string>>> teams;
        string game;
        Texture
            * bg,
            * logo,
            * franjas,
            * xS;

        /********************/
        // Methods

    protected:

    public:
        /********************/
        // Constructor

        MainGameView(RenderWindow* parent, int x, int y, int height, int width, map<string, vector<map<string, string>>> teams, string game);

        /********************/
        // Getters and setters methods

        /********************/
        // Methods

        map<string, vector<string>> dataToSlideableMenuFormat(vector<map<string, string>> players);

        /**
         * \brief Prints the ui on the canvas (doesn't show it on screen).
         */
        void initDrawables();
};
