/************************************************//**
 * \file    MainMenuView.cpp
 * \brief   Here are defined all methods from MainMenuView class
***************************************************/

/**************************************************/
// Libraries

#include <SFML/Graphics.hpp>

#include "MainMenuView.h"
#include "Settings.h"
#include "Title.h"
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

MainMenuView::MainMenuView(int x, int y, int height, int width) : UIElement(x, y, height, width)
{
	if (!logo.loadFromFile("resources\\images\\logo.png") || !bg.loadFromFile("resources\\images\\bg.png"))
	{
		#ifdef _DEBUG
				Console().debug("Error loading image", "There was an error loading logo.png or bg.png", __LINE__, __FILE__, Console::MESSAGE_TYPE::ERR);
		#endif
	}
};

/*****************************/
// Getters and setters methods

/*****************************/
// Medoths

void MainMenuView::draw(RenderTexture& canvas)
{
	Texture texture;
	Sprite sprite;
	Vector2f logoScale = Vector2f((float)(logo.getSize().x * 0.7) / this->width, (float)(this->logo.getSize().x * 0.7) / this->width);
	Title t = Title(0, 0, 100, 10);

	// Convert bg.png (from image -> texture -> sprite) to draw on canvas
	texture.loadFromImage(this->bg);
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setScale(Vector2f((float)this->width / bg.getSize().x, (float)this->height / bg.getSize().y));

	canvas.draw(sprite);

	// Convert logo.png (from image -> texture -> sprite) to draw on canvas
	texture.loadFromImage(this->logo);
	texture.setSmooth(true);
	sprite.setScale(logoScale);
	sprite.setTexture(texture);
	sprite.setPosition(Vector2f((this->width / 2) - (this->logo.getSize().x * (logoScale.x / 2.f)), this->height / 15));
	
	t.draw(canvas);

	canvas.draw(sprite);
};
