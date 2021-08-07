/************************************************//**
 * \file    View.h
***************************************************/

#pragma once

/**************************************************/
// Libraries

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "UIElement.h"

/**************************************************/
// Namespaces

using namespace std;
using namespace sf;

/**************************************************/
/**
 * View class
 * This is an abstract class that is going be inherited by all views.
 */
class MainView : public UIElement
{
    private:

    protected:
        /********************/
        // Variables

        Texture * bg;
        map<string, bool> playAudio;

        /********************/
        // Methods

    public:
        /********************/
        // Constructor

        /**
         * ViewController Constructor.
         *
         * \param parent The windw that contains the element.
         * \param x The x coordinate.
         * \param y The y coordinate.
         * \param height The desired height for the element.
         * \param width The desired width for the element.
         */
        MainView(RenderWindow* parent, int x, int y, int height, int width);

        /********************/
        // Getters and setters methods

        map<string, bool> getPlayAudio();
        void setPlayAudio(map<string, bool> playAudio);

        /********************/
        // Methods
};
