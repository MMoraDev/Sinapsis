/************************************************//**
 * \file    SlideableMenu.cpp
 * \brief   Here are defined all methods from SlideableMenu class
***************************************************/

/**************************************************/
// Libraries

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Button.h"
#include "SlideableMenu.h"
#include "Settings.h"
#include "WrappableText.h"

/**************************************************/
// Dev libraries
#ifdef _DEBUG
	#include "Console.h"
#endif

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

SlideableMenu::SlideableMenu(RenderWindow* parent, int x, int y, int height, int width, map<string, vector<string>> options) : UIElement(parent, x, y, height, width)
{
	vector<Image> tempImages = {
		Image(),
		Image()
	};

	this->options = options;
	this->actualOption = this->options.begin();

	if (!tempImages[0].loadFromFile("resources\\images\\arrow.png") || !tempImages[1].loadFromFile("resources\\images\\arrow-hover.png"))
	{
		#ifdef _DEBUG
				Console().debug("Error loading image", "There was an error loading arrow.png or arrow-hover.png", __LINE__, __FILE__, Console::Message_Type::ERR);
		#endif
	}

	this->arrowImages = tempImages;
};

/*****************************/
// Getters and setters methods

/*****************************/
// Medoths

void SlideableMenu::draw(RenderTexture& canvas)
{
	WrappableText(this->parent, (int)this->x + (this->width / 5), this->y, 50, (int)(this->width * 3)/ 5, this->actualOption->first, PADDING, WrappableText::Style::SUBTITLE, APP_COLORS().GRAY_LIGHT, APP_COLORS().PRIMARY).draw(canvas);
	Button(this->parent, (int)this->x, (int)this->y + 50, 100, 200, arrowImages[0], arrowImages[1]).draw(canvas);
};
