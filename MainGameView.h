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

protected:
    /********************/
    // Variables



    /********************/
    // Methods

public:
    /********************/
    // Constructor

    MainGameView(RenderWindow* parent, int x, int y, int height, int width);

    /********************/
    // Getters and setters methods

    /********************/
    // Methods

    /**
     * \brief Prints the ui on the canvas (doesn't show it on screen).
     */
    void initDrawables();
};
