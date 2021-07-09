/************************************************//**
 * \file    Window.cpp
 * \brief   Here are defined all methods from Button class
***************************************************/

/**************************************************/
// Libraries

#include "Window.h"

/**************************************************/
// Constructor

Window::Window(int width, int height)
{
    this->width = width;
    this->height = height;
};

/**************************************************/
// Public

/*****************************/
// Getters and setters methods

int Window::getWidth() { return this->width; };
void Window::setWidth(int width) { this->width = width; };

int Window::getHeight() { return this->height; };
void Window::setHeight(int height) { this->height = height; };