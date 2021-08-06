/************************************************//**
 * \file    SignUpView.cpp
 * \brief   Here are defined all methods from SignUpView class
***************************************************/

/**************************************************/
// Libraries

#include <SFML/Graphics.hpp>

#include "RoundedRectangle.h"

#include "Button.h"
#include "Settings.h"
#include "SlideableMenu.h"
#include "StorageController.h"
#include "SignUpView.h"
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
// Public

/*****************************/
// Constructor

SignUpView::SignUpView(RenderWindow* parent, int x, int y, int height, int width) : UIElement(parent, x, y, height, width)
{
	this->initDrawables();
};

/*****************************/
// Getters and setters methods

/*****************************/
// Medoths

void SignUpView::initDrawables()
{
	Sprite
		* bgSprite = new Sprite();

	this->bg = new Texture();

	if (!this->bg->loadFromFile("resources\\images\\bg.png"))
	{
		#ifdef _DEBUG
				Console().debug("Error loading image", "There was an error loading logo.png or bg.png", __LINE__, __FILE__, Console::Message_Type::ERR);
		#endif
	}

	// Convert bg.png (from image -> texture -> sprite) to draw on canvas
	this->bg->setSmooth(true);
	bgSprite->setTexture(*(this->bg));
	bgSprite->setScale((float)this->width / this->bg->getSize().x, (float)this->height / this->bg->getSize().y);

	this->drawables["team1"] = new WrappableText(this->parent, (int)this->x + (this->width / 5), this->y, 50, (int)(this->width * 3) / 5, "Equipo rojo", PADDING, WrappableText::Style::SCORE, WrappableText::TextAlign::LEFT, APP_COLORS().PRIMARY, APP_COLORS().PRIMARY);
	this->drawables["bg"] = bgSprite;
};
