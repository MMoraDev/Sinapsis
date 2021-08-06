/************************************************//**
 * \file    UIElement.cpp
 * \brief   Here are defined all methods from UIElement class
***************************************************/

/**************************************************/
// Libraries

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "UIElement.h"

/**************************************************/
// Namespaces

using namespace std;
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

UIElement::UIElement(RenderWindow* parent, int x, int y, int height, int width, bool isClickeable)
{
	this->parent = parent;
	this->x = x;
	this->y = y;
	this->height = height;
	this->width = width;
	this->isClickeable = isClickeable;
	this->isMouseInside = false;
	this->isRedrawNeeded = true;

	this->bounds.setPosition((float)this->x, (float)this->y);
	this->bounds.setSize({ (float)this->width, (float)this->height });
};

/*****************************/
// Getters and setters methods

int UIElement::getHeight() { return this->height; };
void UIElement::setHeight(int height)
{
	this->height = height;
	this->bounds.setSize(Vector2f((float)this->width, (float)this->height));
};

int UIElement::getWidth() { return this->width; };
void UIElement::setWidth(int width)
{
	this->width = width;
	this->bounds.setSize(Vector2f((float)this->width, (float)this->height));
};

int UIElement::getX() { return this->x; };
void UIElement::setX(int x)
{
	this->x = x;
	this->bounds.setPosition(Vector2f((float)this->x, (float)this->y));
};

int UIElement::getY() { return this->y; };
void UIElement::setY(int y)
{
	this->y = y;
	this->bounds.setPosition(Vector2f((float)this->x, (float)this->y));
};

/*****************************/
// Methods
void UIElement::draw(RenderTarget& target, RenderStates states) const
{
	const_cast<UIElement*>(this)->loop();

	for (const auto& d : this->drawables)
	{
		target.draw(*d.second, states);
	}
};

bool UIElement::isMouseOver()
{
	if (this != NULL)
	{
		Vector2f mousePos = static_cast<Vector2f>(this->parent->mapPixelToCoords(Mouse::getPosition(*this->parent)));

		if (this->bounds.getGlobalBounds().contains(mousePos))
		{
			Cursor cursor;

			this->setCursor(Cursor::Hand);
			this->isMouseInside = true;

			return true;
		}

		if (this->isMouseInside)
		{
			this->setCursor(Cursor::Arrow);
			this->isMouseInside = false;
		}
	}

	return false;
};

void UIElement::loop()
{

};
