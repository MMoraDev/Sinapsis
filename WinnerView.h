/************************************************//**
 * \file    WinnerView.h
***************************************************/

#pragma once

/**************************************************/
// Libraries

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "MainView.h"

/**************************************************/
// Namespaces

using namespace std;
using namespace sf;

/**************************************************/
/**
 * MainMenuView class
 */
class WinnerView : public MainView
{
private:
    /********************/
    // Variables
    Texture
        * bg,
        * logo,
        * franjaIzq,
        * franjaDer;
    string winner;
    bool isDone;

    /********************/
    // Methods
    void loop();
protected:

public:
    /********************/
    // Constructor

    WinnerView(RenderWindow* parent, int x, int y, int height, int width, string winner);

    /********************/
    // Getters and setters methods
    bool getIsDone();
    void setIsDone(bool isDone);

    /********************/
    // Methods

    /**
     * \brief Prints the ui on the canvas (doesn't show it on screen).
     */
    void initDrawables();
};
