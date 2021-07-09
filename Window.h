/************************************************//**
 * \file    Window.h
***************************************************/

#pragma once

/**************************************************/
/**
 * Window class
 * This is an abstract class that is going be inherited by all windows.
 */
class Window
{
    private:

    protected:
        /********************/
        // Variables

        int
            width = 0,
            height = 0;

        /********************/
        // Methods

        /**
         * \brief Creates the window's background, etc, but doesn`t show it until render.
         */
        virtual void draw() = 0;

    public:
        /********************/
        // Constructor

        /**
         * Button Constructor.
         *
         * \param width The desired width for the window.
         * \param height The desired height for the window.
         */
        Window(int width, int height);

        /********************/
        // Getters and setters methods

        int getWidth();
        void setWidth(int width);

        int getHeight();
        void setHeight(int height);

        /********************/
        // Methods

        /**
         * \brief Prints the button on screen.
         */
        virtual void render() = 0;
};
