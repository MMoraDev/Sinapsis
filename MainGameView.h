/************************************************//**
 * \file    MainGameView.h
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
class MainGameView : public MainView
{
    private:
        /********************/
        // Variables
        short int
            scores[2],
            round;
        map<string, bool> playAudio;
        map<string, vector<map<string, string>>> teams;
        map<string, map<string, int>>
            questions, 
            actualQuestion;
        string gameMode;
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

        MainGameView(RenderWindow* parent, int x, int y, int height, int width, map<string, vector<map<string, string>>> teams, string gameMode);

        /********************/
        // Getters and setters methods
        map<string, map<string, int>> getRandomQuestion();

        /********************/
        // Methods

        map<string, vector<string>> dataToSlideableMenuFormat(vector<map<string, string>> players);

        //map<string, map<string, int>> getRandomQuestion ()

        /**
         * \brief Prints the ui on the canvas (doesn't show it on screen).
         */
        void initDrawables();

        int generateRandomNumber(int max, int min = 0);

        void playRound(string round);

};
