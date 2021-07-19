/************************************************//**
 * \file    MainMenuView.cpp
 * \brief   Here are defined all methods from MainMenuView class
***************************************************/

/**************************************************/
// Libraries

#include <SFML/Graphics.hpp>

#include "MainMenuView.h"

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
// Getters and setters methods

/*****************************/
// Medoths

void MainMenuView::draw(RenderTexture& canvas)
{
	Image image;
	Texture texture;
	Sprite sprite;

	if (image.loadFromFile("resources\\images\\logo.png"))
	{
		// Convert logo.png (from image -> texture -> sprite) to draw on canvas
		texture.loadFromImage(image);
		sprite.setTexture(texture);
	}
	else
	{
		#ifdef _DEBUG
				Console().debug("Error loading image", "There was an error loading the logo.png", __LINE__, __FILE__, Console::MESSAGE_TYPE::ERR);
		#endif
	}

	canvas.draw(sprite);
};
