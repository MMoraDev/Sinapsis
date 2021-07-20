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
#include "StorageController.h"

/**************************************************/
// Dev libraries
#ifdef _DEBUG
    #include "Console.h"
#endif

/**************************************************/
//      Comments
//!     These are important comments
//?     These are questions
//TODO  These are tasks to do
//x     These are completed tasks
//      https://marketplace.visualstudio.com/items?itemName=OmarRwemi.BetterComments

/**************************************************/
#ifndef _DEBUG
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
#else
    int main() // While debugging, it allows us to print on console
#endif
{
    #ifdef _DEBUG
            Console().debug("Welcome", "José Gutiérrez & Miguel De La Mora welcome you, developer.", __LINE__, __FILE__, Console::MESSAGE_TYPE::FRIENDLY);
    #endif

    // Variables
    MainController mainCtrl = MainController();

    mainCtrl.run();

    storageController::readFile();

    return 0;
}