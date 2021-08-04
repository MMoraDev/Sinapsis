/************************************************//**
 * \file    MainGameView.cpp
 * \brief   Here are defined all methods from MainGameView class
***************************************************/

/**************************************************/
// Libraries

#include <SFML/Graphics.hpp>

#include "RoundedRectangle.h"

#include "Button.h"
#include "MainGameView.h"
#include "Settings.h"
#include "SlideableMenu.h"
#include "StorageController.h"
#include "UIElement.h"
#include "WrappableText.h"

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

MainGameView::MainGameView(RenderWindow* parent, int x, int y, int height, int width) : UIElement(parent, x, y, height, width)
{
	this->initDrawables();
};

/*****************************/
// Getters and setters methods

/*****************************/
// Medoths

void MainGameView::initDrawables()
{
	Sprite
		* bgSprite = new Sprite();
	
	this->bg = new Texture();

	if (!this->bg->loadFromFile("resources\\images\\bg.png"))
	{
		#ifdef _DEBUG
			Console().debug("Error loading image", "There was an error loading bg.png", __LINE__, __FILE__, Console::Message_Type::ERR);
		#endif
	}
	
	// Convert bg.png (from image -> texture -> sprite) to draw on canvas
	bg->setSmooth(true);
	bgSprite->setTexture(*bg);
	bgSprite->setScale((float)this->width / bg->getSize().x, (float)this->height / bg->getSize().y);

	this->drawables["bg"] = bgSprite;
};
