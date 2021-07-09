/************************************************//**
 * \file    WindowController.cpp
 * \brief   Here are defined all methods from WindowController class
***************************************************/

/**************************************************/
// Libraries

#include "WindowController.h"

/**************************************************/
// Public

/*****************************/
// Getters and setters methods

int WindowController::getWidth() { return this->width; };
void WindowController::setWidth(int width) { this->width = width; };

int WindowController::getHeight() { return this->height; };
void WindowController::setHeight(int height) { this->height = height; };