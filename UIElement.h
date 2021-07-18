/************************************************//**
 * \file    UIElement.h
***************************************************/

#pragma once

/**************************************************/
/**
 * UIElement class
 * This is an abstract class that is going be inherited by all classes that need to print on screen.
 */
class UIElement
{
    private:

    protected:
        /********************/
        // Variables

        float
            height = 0,
            width = 0,
            x = 0.0,
            y = 0.0;

        /********************/
        // Methods

        virtual void draw() = 0;

    public:
        /********************/
        // Getters and setters methods

        int getHeight();
        void setHeight(int height);

        int getWidth();
        void setWidth(int width);

        float getX();
        void setX(float x);

        float getY();
        void setY(float y);

        /********************/
        // Methods

        /**
         * /brief Prints the ui on the canvas (doesn't show it on screen).
         * 
         * \param canvas
         */
        virtual void draw(RenderTexture& canvas) = 0;
};
