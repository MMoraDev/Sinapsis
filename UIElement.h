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
            x = 0.0,
            y = 0.0;

        /********************/
        // Methods

        virtual void draw() = 0;

    public:
        /********************/
        // Getters and setters methods

        virtual float getX();
        virtual void setX(float);

        virtual float getY();
        virtual void setY(float);

        /********************/
        // Methods

        /**
         * @brief Prints on screen the object
         *
         */
        virtual void render() = 0;
};
