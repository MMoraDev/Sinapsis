/************************************************//**
 * \file    main.cpp
 * \author  Jose Ignacio Gutierres Mayorquin & Miguel Angel De La Mora Segura
 * \date    08/07/2021
***************************************************/

/**************************************************/
// Libraries

#define NOMINMAX                // Prevents SFML Graphic errors caused by windows.h
#include <windows.h>            // WinMain parameters

#include "MainController.h"

/**************************************************/
//      Comments
//!     These are important comments
//?     These are questions
//TODO  These are tasks to do
//x     These are completed tasks
//      https://marketplace.visualstudio.com/items?itemName=OmarRwemi.BetterComments

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
    // Variables
    MainController mainCtrl = MainController();

    mainCtrl.run();

    return 0;
}