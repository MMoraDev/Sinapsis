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
};
