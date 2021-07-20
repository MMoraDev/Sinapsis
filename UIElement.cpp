/************************************************//**
 * \file    UIElement.cpp
 * \brief   Here are defined all methods from UIElement class
***************************************************/

/**************************************************/
// Libraries

#include <SFML/Graphics.hpp>

#include "UIElement.h"

/**************************************************/
// Namespaces

using namespace sf;

/**************************************************/
// Public

/*****************************/
// Constructor

UIElement::UIElement(int x, int y, int height, int width)
{
	this->x = x;
	this->y = y;
	this->height = height;
	this->width = width;
};


/*****************************/
// Getters and setters methods

int UIElement::getHeight() { return this->height; };
void UIElement::setHeight(int height) { this->height = height; };

int UIElement::getWidth() { return this->width; };
void UIElement::setWidth(int width) { this->width = width; };

int UIElement::getX() { return this->x; };
void UIElement::setX(int x) { this->x = x; };

int UIElement::getY() { return this->y; };
void UIElement::setY(int y) { this->y = y; };