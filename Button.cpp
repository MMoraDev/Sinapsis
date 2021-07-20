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
// Protected

/*****************************/
// Medoths

/**************************************************/
// Public

/**************************************************/
// Constructor

Button::Button(Window* parent, int x, int y, int height, int width, Image bg, Image onHoverBg) : UIElement(parent, x, y, height, width, true)
{
	this->bg = bg;
	this->onHoverBg = onHoverBg;
	this->type = Type::IMAGE;
};

/*****************************/
// Getters and setters methods

/*****************************/
// Medoths

void Button::draw(RenderTexture& canvas)
{
	Texture texture;
	Sprite sprite;

	if (this->type == Type::IMAGE)
	{
		// Convert bg.png (from image -> texture -> sprite) to draw on canvas
		texture.loadFromImage(this->isMouseOver() ? this->onHoverBg : this->bg);
		texture.setSmooth(true);
		sprite.setTexture(texture);
		sprite.setScale((float)this->width / bg.getSize().x, (float)this->height / bg.getSize().y);
		sprite.setPosition((float)this->x, (float)this->y);

		canvas.draw(sprite);
	}
};
