/************************************************//**
 * \file    Button.cpp
 * \brief   Here are defined all methods from Button class
***************************************************/

/**************************************************/
// Libraries

#include <SFML/Graphics.hpp>

#include <iostream>
#include "Button.h"
#include <vector>

/**************************************************/
// Namespaces

using namespace std;
using namespace sf;

/**************************************************/
// Private

/*****************************/
// Methods

void Button::draw(RenderTarget& target, RenderStates states) const
{
	if (const_cast<Button*>(this)->isMouseOver())
	{
		if (this->type == Type::IMAGE)
		{
			target.draw(*const_cast<Button*>(this)->drawables["onHoverBg"], states);
		}
	}
	else
	{
		if (this->type == Type::IMAGE)
		{
			target.draw(*const_cast<Button*>(this)->drawables["bg"], states);
		}
	}
};

/**************************************************/
// Public

/**************************************************/
// Constructor

Button::Button(RenderWindow* parent, int x, int y, int height, int width, Image bg, Image onHoverBg) : UIElement(parent, x, y, height, width, true)
{
	Texture
		*bgTexture = new Texture(),
		*onHoverBgTexture = new Texture();
	
	bgTexture->loadFromImage(bg);
	onHoverBgTexture->loadFromImage(onHoverBg);

	this->bg = bgTexture;
	this->onHoverBg = onHoverBgTexture;
	this->type = Type::IMAGE;

	this->initDrawables();
};

/*****************************/
// Getters and setters methods

/*****************************/
// Medoths

void Button::initDrawables()
{
	Sprite
		*bgSprite = new Sprite(),
		*onHoverBgSprite = new Sprite();

	if (this->type == Type::IMAGE)
	{
		// Convert bg.png (from image -> texture -> sprite) to draw on canvas
		this->bg->setSmooth(true);
		bgSprite->setTexture(*this->bg);
		bgSprite->setScale((float)this->width / bg->getSize().x, (float)this->height / bg->getSize().y);
		bgSprite->setPosition((float)this->x, (float)this->y);

		this->drawables["bg"] = bgSprite;

		// Convert bg.png (from image -> texture -> sprite) to draw on canvas
		this->onHoverBg->setSmooth(true);
		onHoverBgSprite->setTexture(*this->onHoverBg);
		onHoverBgSprite->setScale((float)this->width / onHoverBg->getSize().x, (float)this->height / onHoverBg->getSize().y);
		onHoverBgSprite->setPosition((float)this->x, (float)this->y);

		this->drawables["onHoverBg"] = onHoverBgSprite;
	}
};
