/**************************************************//**
 * @file StorageController.cpp
 * @brief Here are defined all methods from StorageController class
/**************************************************/

/**************************************************/
//Libraries

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "StorageController.h"

/**************************************************/
// Dev libraries
#ifdef _DEBUG
    #include "Console.h"
#endif

/**************************************************/
//Namespaces

using namespace std;

/**************************************************/
// Public

/*****************************/
// Methods
void storageController::readFile() {

    ifstream file;
    string text;

    file.open("file.csv", ios::in);
    
    if (file.fail()) {
        #ifdef _DEBUG
                Console().debug("Error loading file", "There has been an error while opening the file.", __LINE__, __FILE__, Console::Message_Type::ERR);
        #endif
    }

    while (!file.eof()) {
        getline(file, text, ',');
        cout << text << endl;
    }

    file.close();
}

/*********************************************/
//Libraries

/*********************************************/
//Libraries