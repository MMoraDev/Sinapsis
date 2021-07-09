/************************************************//**
 * \file    main.cpp
 * \author  Jose Ignacio Gutierres Mayorquin & Miguel Angel De La Mora Segura
 * \date    08/07/2021
***************************************************/

/**************************************************/
// Libraries

#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>

#include "Settings.h"

/**************************************************/
// Namespaces

using namespace sf;
using namespace std;

/**************************************************/
/**
 * Main function of the app.
 * 
 * \param hThisInstance
 * \param hPrevInstance
 * \param lpszArgument
 * \param nCmdShow
 * \return int
 */
int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow)
{
    RenderWindow mainWindow(VideoMode(200, 200), APP_TITLE);
    CircleShape shape(100.f);
    shape.setFillColor(Color::Green);

    while (mainWindow.isOpen())
    {
        Event event;
        while (mainWindow.pollEvent(event))
        {
            if (event.type == Event::Closed)
                mainWindow.close();
        }

        mainWindow.clear();
        mainWindow.draw(shape);
        mainWindow.display();
    }

    return 0;
}