/************************************************//**
 * \file    Button.cpp
 * \brief   Here are defined all methods from Button class
***************************************************/

/**************************************************/
// Libraries

#include "Button.h"

/**************************************************/
// Constructor

Button::Button(int width, int height)
{
    this->width = width;
    this->height = height;
};

/**************************************************/
// Protected

/*****************************/
// Medoths

void Button::draw() {

};

/**************************************************/
// Public

/*****************************/
// Getters and setters methods

int Button::getWidth() { return this->width; };
void Button::setWidth(int width) { this->width = width; };

int Button::getHeight() { return this->height; };
void Button::setHeight(int height) { this->height = height; };

/*****************************/
// Medoths

void Button::render() {

};