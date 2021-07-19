/************************************************//**
 * \file    WindowController.cpp
 * \brief   Here are defined all methods from WindowController class
***************************************************/

/**************************************************/
// Libraries

#include "MainController.h"
#include "WindowController.h"

/**************************************************/
// Public

/*****************************/
// Constructor
WindowController::WindowController(int height, int width)
{
	this->currentState = MainController::State::MAIN_MENU;
	this->height = height;
	this->width = width;
}

/*****************************/
// Getters and setters methods

int WindowController::getWidth() { return this->width; };
void WindowController::setWidth(int width) { this->width = width; };

int WindowController::getHeight() { return this->height; };
void WindowController::setHeight(int height) { this->height = height; };

/*****************************/
// Methods

void WindowController::setState(MainController::State newState)
{
	this->currentState = newState;
}
