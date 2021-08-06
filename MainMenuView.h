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
        /********************/
        // Methods

        void loop() override;


    protected:
        /********************/
        // Variables

<<<<<<< Updated upstream
        Texture 
            *logo,
            *bg;
        map<string, vector<string>> options;
        map<string, string> selectedOption;
=======
        Texture
            * logo,
            * bg;
        map<string, vector<string>>
            options;
>>>>>>> Stashed changes

        /********************/
        // Methods

    public:
        /********************/
        // Constructor

        MainMenuView(RenderWindow* parent, int x, int y, int height, int width);

        /********************/
        // Getters and setters methods

        map<string, string> getSelectedOption();
        void setSelectedOption(map<string, string> option);

        /********************/
        // Methods

        /**
         * \brief Prints the ui on the canvas (doesn't show it on screen).
         */
        void initDrawables();
};
