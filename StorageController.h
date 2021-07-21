/**************************************************//**
 * @file StorageController.h
/**************************************************/

#pragma once

/**************************************************/
// Libraries

#include <iostream>
#include <SFML/Graphics.hpp>

/**************************************************/
// Namespaces

using namespace std;
using namespace sf;

/**
 * StorageManager class
 */
class StorageController {

    private:

    protected:

    public:
        /*******************/
        //Methods

        /**
         * Search in resources/data all files.
         * 
         * \return a vector of strings with the names (without extension) of the founded files
         */
        static vector<string> findGameModes();

        static map<string, map<string, int>> readFile(string filename);

};