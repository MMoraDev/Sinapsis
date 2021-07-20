/************************************************//**
 * \file    Cosnole.h
***************************************************/

#pragma once

/**************************************************/
// Libraries

#include <iostream>
#include <windows.h>

/**************************************************/
// Namespaces

using namespace std;

/**************************************************/
/**
 * Console class
 */
class Console
{
    private:
        /********************/
        // Constants
        // https://ss64.com/nt/syntax-ansi.html
        const enum class Style {
            RESET = 7,
            BLACK = 0,
            RED = 5,
            YELLOW = 6,
            PURPLE = 5,
            PINK = 12,
            GREEN = 2,
            BLUE = 1,
            CYAN = 11,
            WHITE = 7,
            ERR = 79,
            WARNING = 111,
            FRIENDLY = 159,
        };

        /********************/
        // Methods

        /**
         * Sets the color style for cout.
         * 
         * \param style
         */
        static void setStyle(Style style);

    public:
        /********************/
        // Enums
        const enum class Message_Type {
            DEFAULT,
            WARNING,
            ERR,
            FRIENDLY,
        };

        const enum class Message_Part {
            TITLE,
            MESSAGE,
            LINE,
            FILE,
        };

        /********************/
        // Methods

        /**
         * Prints on console the message.
         * 
         * \param title
         * \param message
         * \param line
         * \param file
         * \param type
         */
        static void debug(string title, string message, int line, string file, Message_Type type = Message_Type::DEFAULT);

        /**
         * \param type
         * \param part
         * \return 
         */
        static Style getColorByType(Message_Type type, Message_Part part);
};
