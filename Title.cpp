/************************************************//**
 * \file    Title.cpp
 * \brief   Here are defined all methods from Title class
***************************************************/

/**************************************************/
// Libraries

#include <SFML/Graphics.hpp>

#include "RoundedRectangle.h"
#include "Title.h"

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
// Getters and setters methods

/*****************************/
// Medoths

void Title::draw(RenderTexture& canvas)
{
	RoundedRectangle(0, 0, 100, 100, 10, Color::Red, 0, Color::Transparent).draw(canvas);
};
