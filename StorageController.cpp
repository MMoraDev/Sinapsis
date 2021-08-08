/**************************************************//**
 * @file StorageController.cpp
 * @brief Here are defined all methods from StorageController class
/**************************************************/

/**************************************************/
//Libraries

#include <iostream>
#include <filesystem>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <locale.h>
#include <map>

#include "Settings.h"
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

vector<string> StorageController::getFilesNames(string path)
{
    vector<string> modes = vector<string>();

    for (const auto& entry : filesystem::directory_iterator(path))
    {
        modes.push_back(entry.path().stem().u8string());
    }

    return modes;
};

map<string, map<string, int>> StorageController::readFile(string filename)
{
    ifstream file;
    string
        text, 
        text2, 
        text3, 
        question;
    int points, pos;

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

        if (text[0] == '\n')
        {
            question = text.substr(1, text.size() - 1);
        }

        while (text != '\n' && text2 != "*")
        {
            getline(file, text2, ',');
            getline(file, text3, ',');

            points = stoi(text3);
            res[question][text2] = points;
            
            pos = file.tellg();
            getline(file, text2, ',');

            if (text2 == '*')
            {
                text2 = "a";
                break;
            }
            else
            {
                file.seekg(pos);
            }
            
        }
    }

    file.close();

    return res;
}