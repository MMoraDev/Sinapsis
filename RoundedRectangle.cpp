/************************************************//**
 * \file    RoundedRectangle.cpp
 * \brief   Here are defined all methods from RoundedRectangle class
***************************************************/

/**************************************************/
// Libraries

#include <SFML/Graphics.hpp>

#include "RoundedRectangle.h"
#include "Settings.h"
#include "UIElement.h"

/**************************************************/
// Dev libraries
#ifdef _DEBUG
	#include "Console.h"
#endif

/**************************************************/
// Namespaces

using namespace sf;

/**************************************************/
// Constructor

/**************************************************/
// Protected

/*****************************/
// Medoths

/**************************************************/
// Public

/*****************************/
// Constructor

RoundedRectangle::RoundedRectangle(RenderWindow* parent, int x, int y, int height, int width, float radius, const Color& fillColor, float outline, const Color& outlineColor) : UIElement(parent, x, y, height, width)
{
	this->radius = radius;
	this->outline = outline;
	this->fillColor = fillColor;
	this->outlineColor = outlineColor;
};

/*****************************/
// Getters and setters methods

/*****************************/
// Medoths

void RoundedRectangle::draw(RenderTexture& canvas)
{
	ConvexShape* rrect = new ConvexShape();
	float
		X = 0,
		Y = 0;
	int counter = 0;

	rrect->setOutlineThickness(this->outline);
	rrect->setFillColor(this->fillColor);
	rrect->setOutlineColor(this->outlineColor);
	rrect->setPointCount(this->POINTS * 4);

	for (int i = 0; i < this->POINTS; i++)
	{
		X += this->radius / this->POINTS;
		Y = sqrt(this->radius * this->radius - X * X);
		rrect->setPoint(counter++, Vector2f(X + x + this->width - this->radius, y - Y + this->radius));
	}
	Y = 0;
	for (int i = 0; i < this->POINTS; i++)
	{
		Y += this->radius / this->POINTS;
		X = sqrt(this->radius * this->radius - Y * Y);
		rrect->setPoint(counter++, Vector2f(x + this->width + X - this->radius, y + this->height - this->radius + Y));
	}
	X = 0;
	for (int i = 0; i < this->POINTS; i++)
	{
		X += this->radius / this->POINTS;
		Y = sqrt(this->radius * this->radius - X * X);
		rrect->setPoint(counter++, Vector2f(x + this->radius - X, y + this->height - this->radius + Y));
	}
	Y = 0;
	for (int i = 0; i < this->POINTS; i++)
	{
		Y += this->radius / this->POINTS;
		X = sqrt(this->radius * this->radius - Y * Y);
		rrect->setPoint(counter++, Vector2f(x - X + this->radius, y + this->radius - Y));
	}

	canvas.draw(*rrect);
};
