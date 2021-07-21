/**************************************************//**
 * @file StorageController.cpp
 * @brief Here are defined all methods from StorageController class
/**************************************************/

/**************************************************/
//Libraries

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <locale.h>

#include "StorageController.h"

/**************************************************/
// Dev libraries
#ifdef _DEBUG
    #include "Console.h"
#endif

/**************************************************/
//Namespaces

using namespace std;
using namespace sf;

/**************************************************/
// Public

/*****************************/
// Methods
map<string, map<string, int>> StorageController::readFile(string filename)
{
    ifstream file;
    string text;
    map<string, map<string, int>> res = map<string, map<string, int>>();

    setlocale(LC_CTYPE, "Spanish");
    file.open(filename, ios::in);
    
    if (file.fail())
    {
        #ifdef _DEBUG
                Console().debug("Error loading file", "There has been an error while opening the file.", __LINE__, __FILE__, Console::Message_Type::ERR);
        #endif
    }

    while (!file.eof())
    {
        getline(file, text, ',');
        #ifdef _DEBUG
                Console().debug("File", text, __LINE__, __FILE__);
        #endif
    }

    file.close();

    return res;
}