/************************************************//**
 * \file    SlideableMenu.cpp
 * \brief   Here are defined all methods from SlideableMenu class
***************************************************/

/**************************************************/
// Libraries

#include <SFML/Graphics.hpp>

#include "SlideableMenu.h"
#include "Settings.h"
#include "WrappableText.h"

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

void SlideableMenu::draw(RenderTexture& canvas)
{
	WrappableText((int)this->x + (this->width / 5), this->y, 50, (int)(this->width * 3)/ 5, "Modo de juego", PADDING, WrappableText::Style::SUBTITLE, APP_COLORS().GRAY_LIGHT, APP_COLORS().PRIMARY).draw(canvas);
};
