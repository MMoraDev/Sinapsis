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
        /*******************/
        //Variables
        
        /*******************/
        //Methods

    public:
        
        static map<string, map<string, int>> readFile(string filename);

};