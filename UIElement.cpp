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
// Protected

/*****************************/
// Methods

void UIElement::setCursor(Cursor::Type cursor)
{
	Cursor c;

	if (this->isClickeable && c.loadFromSystem(cursor))
		this->parent->setMouseCursor(c);
};

/**************************************************/
// Public

/*****************************/
// Constructor

UIElement::UIElement(Window* parent, int x, int y, int height, int width, bool isClickeable)
{
	this->parent = parent;
	this->x = x;
	this->y = y;
	this->height = height;
	this->width = width;
	this->isClickeable = isClickeable;
	this->isMouseInside = false;
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

/*****************************/
// Methods

bool UIElement::isMouseOver()
{
	Vector2i mousePos = Mouse::getPosition(*this->parent);

	if (mousePos.x >= this->x
		&& mousePos.x <= this->x + this->width
		&& mousePos.y >= this->y
		&& mousePos.y <= this->y + this->height)
	{
		Cursor cursor;

		this->setCursor(Cursor::Hand);
		this->isMouseInside = true;

		return true;
	}

	this->setCursor(Cursor::Arrow);
	this->isMouseInside = false;

	return false;
};
