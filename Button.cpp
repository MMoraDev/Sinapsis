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
#include "WrappableText.h"

/**************************************************/
// Namespaces

using namespace std;
using namespace sf;

/**************************************************/
// Private

/*****************************/
// Medoths

void Button::loop()
{
	Sprite* sprite = new Sprite();
	Texture* texture = new Texture();
	Color color = Color();

	if (this->isMouseOver())
	{
		if (this->type == Type::IMAGE)
		{
			texture = this->onHoverBg;
		}
		else if (this->type == Type::TEXT)
		{
			this->drawables["bg"] = new WrappableText(this->parent, (int)this->x, (int)this->y, (int)this->height, (int)this->width, this->text, PADDING, WrappableText::Style::SUBTITLE, WrappableText::TextAlign::CENTER, this->fontColor, this->bgColor);
		}
	}
	else
	{
		if (this->type == Type::IMAGE)
		{
			texture = this->bg;
		}
		else if (this->type == Type::TEXT)
		{
			this->drawables["bg"] = new WrappableText(this->parent, (int)this->x, (int)this->y, (int)this->height, (int)this->width, this->text, PADDING, WrappableText::Style::SUBTITLE, WrappableText::TextAlign::CENTER, this->fontColor, this->onHoverBgColor);
		}
	}

	if (this->type == Type::IMAGE)
	{
		// Convert png (from texture -> sprite) to draw on canvas
		texture->setSmooth(true);
		sprite->setTexture(*texture);
		sprite->setScale((float)this->width / texture->getSize().x, (float)this->height / texture->getSize().y);
		sprite->setPosition((float)this->x, (float)this->y);
		color = sprite->getColor();
		color.a = this->opacity;
		sprite->setColor(color);

		this->drawables["bg"] = sprite;
	}
};

/**************************************************/
// Public

/**************************************************/
// Constructor

Button::Button(RenderWindow* parent, int x, int y, int height, int width, Image bg, Image onHoverBg, int opacity, bool isVisible) : UIElement(parent, x, y, height, width, true, isVisible)
{
	Texture
		*bgTexture = new Texture(),
		*onHoverBgTexture = new Texture();
	
	bgTexture->loadFromImage(bg);
	onHoverBgTexture->loadFromImage(onHoverBg);

	this->bg = bgTexture;
	this->onHoverBg = onHoverBgTexture;
	this->opacity = opacity;
	this->type = Type::IMAGE;
	this->isReleased = true;

	this->initDrawables();
};

Button::Button(RenderWindow* parent, int x, int y, int height, int width, string text, Color font, Color bg, Color onHoverBg, bool isVisible) : UIElement(parent, x, y, height, width, true, isVisible)
{
	this->text = text;
	this->fontColor = font;
	this->bgColor = bg;
	this->onHoverBgColor = onHoverBg;
	this->opacity = 255;
	this->type = Type::TEXT;
	this->isReleased = true;

	this->initDrawables();
};

/*****************************/
// Getters and setters methods

int Button::getOpacity() { return this->opacity; };
void Button::setOpacity(int opacity) { this->opacity = opacity; };

/*****************************/
// Medoths

void Button::initDrawables()
{

};

bool Button::isClicked()
{
	if (this != NULL)
	{
		if (this->isMouseOver() && Mouse::isButtonPressed(Mouse::Left) && this->isReleased)
		{
			this->isReleased = false;
			return true;
		}
		else if (!Mouse::isButtonPressed(Mouse::Left))
		{
			this->isReleased = true;
		}
	}

	return false;
};
