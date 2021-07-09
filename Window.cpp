/************************************************//**
 * \file    Window.cpp
 * \brief   Here are defined all methods from Button class
***************************************************/

/**************************************************/
// Libraries

#include "Window.h"

/**************************************************/
// Public

/*****************************/
// Getters and setters methods

int Window::getWidth() { return this->width; };
void Window::setWidth(int width) { this->width = width; };

int Window::getHeight() { return this->height; };
void Window::setHeight(int height) { this->height = height; };