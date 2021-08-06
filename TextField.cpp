/************************************************//**
 * \file    TextField.cpp
 * \brief   Here are defined all methods from TextField class
***************************************************/

/**************************************************/
// Libraries

#include <iostream>
#include <SFML/Graphics.hpp>

#include "RoundedRectangle.h"
#include "Settings.h"
#include "TextField.h"
#include "WrappableText.h"

/**************************************************/
// Dev libraries
#ifdef _DEBUG
	#include "Console.h"
#endif

/**************************************************/
// Namespaces

using namespace std;
using namespace sf;

/**************************************************/
// Private

/*****************************/
// Medoths

void TextField::loop()
{
	if (this->isMouseOver())
	{

	}
};

/**************************************************/
// Public

/*****************************/
// Constructor

TextField::TextField(RenderWindow* parent, int x, int y, int height, int width, string text, Vector2f padding, Style style, TextAlign alignment, Color fontColor, Color bgColor, float borderRadius) : WrappableText(parent, x, y, height, width, text, padding, style, alignment, fontColor, bgColor, true, borderRadius, true)
{

};


/*****************************/
// Getters and setters methods

/*****************************/
// Medoths

void TextField::initDrawables()
{
	WrappableText::initDrawables();
};