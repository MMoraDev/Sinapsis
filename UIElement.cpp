/************************************************//**
 * \file    UIElement.cpp
 * \brief   Here are defined all methods from UIElement class
***************************************************/

/**************************************************/
// Libraries

#include "UIElement.h"

/**************************************************/
// Public

/*****************************/
// Getters and setters methods

int UIElement::getHeight() { return this->height; };
void UIElement::setHeight(int height) { this->height = height; };

int UIElement::getWidth() { return this->width; };
void UIElement::setWidth(int width) { this->width = width; };

float UIElement::getX() { return this->x; };
void UIElement::setX(float x) { this->x = x; };

float UIElement::getY() { return this->y; };
void UIElement::setY(float y) { this->y = y; };