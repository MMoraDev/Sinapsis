/************************************************//**
 * \file    SlideableMenu.cpp
 * \brief   Here are defined all methods from SlideableMenu class
***************************************************/

/**************************************************/
// Libraries

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
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
// Public

/**************************************************/
// Constructor

SlideableMenu::SlideableMenu(RenderWindow* parent, int x, int y, int height, int width, map<string, vector<string>> options) : UIElement(parent, x, y, height, width)
{
	vector<Image> tempImages = {
		Image(),
		Image(),
		Image(),
		Image()
	};

	this->options = options;
	this->actualOption = this->options.begin();
	this->gap = 0;

	if (!tempImages[0].loadFromFile("resources\\images\\arrow.png") || !tempImages[1].loadFromFile("resources\\images\\arrow-hover.png"))
	{
		#ifdef _DEBUG
				Console().debug("Error loading image", "There was an error loading arrow.png or arrow-hover.png", __LINE__, __FILE__, Console::Message_Type::ERR);
		#endif
	}
	else
	{
		tempImages[2] = tempImages[0];
		tempImages[3] = tempImages[1];
		tempImages[2].flipHorizontally();
		tempImages[3].flipHorizontally();
	}

	this->arrowImages = tempImages;

	this->initDrawables();
};

/*****************************/
// Getters and setters methods

/*****************************/
// Medoths

void SlideableMenu::changeOption(map<string, vector<string>>::iterator option, Direction direction)
{
	if (direction == Direction::LEFT)
	{
		if (this->gap < MAX_GAP)
			this->gap++;
	}
	else
	{
		if (this->gap < MAX_GAP)
			this->gap++;
	}
};

void SlideableMenu::initDrawables()
{
	const Vector2f CENTER = Vector2f((float)(this->x + (this->width / 2)), (float)(this->y + (this->height / 2)));
	CircleShape* circle = new CircleShape();
	Image image;
	Texture texture;
	if (!image.loadFromFile("resources\\images\\" + this->actualOption->second[0] + ".png"))
	{
		#ifdef _DEBUG
				Console().debug("Error loading image", "There was an error loading menu image", __LINE__, __FILE__, Console::Message_Type::ERR);
		#endif
	}

	float rescaleFactor = 120 / (float)image.getSize().y;

	circle->setRadius(50);
	circle->setFillColor(APP_COLORS().GRAY);
	circle->setPosition((float) (CENTER.x - 50), (float) (this->y + 55 + 37.5));

	// Convert from image -> texture -> sprite to draw on canvas
	texture.loadFromImage(image);
	texture.setSmooth(true);

	this->drawables["sectionText"] = new WrappableText(this->parent, (int)this->x + (this->width / 5), this->y, 50, (int)(this->width * 3) / 5, this->actualOption->first, PADDING, WrappableText::Style::SUBTITLE, WrappableText::TextAlign::CENTER, APP_COLORS().GRAY_LIGHT, APP_COLORS().PRIMARY);
	this->drawables["backButton"] = new Button(this->parent, (int)this->x, (int)this->y + 55 + 50, 75, 26, arrowImages[0], arrowImages[1]);
	this->drawables["bg"] = circle;
	this->drawables["optionButton"] = new Button(this->parent, (int)(CENTER.x - (texture.getSize().x * rescaleFactor / 2)), (int)(this->y + 82.5), 120, texture.getSize().x * rescaleFactor, image, image);
	this->drawables["nextButton"] = new Button(this->parent, (int)(this->x + this->width - 26), (int)this->y + 55 + 50, 75, 26, arrowImages[2], arrowImages[3]);
	this->drawables["optionText"] = new WrappableText(this->parent, (int)this->x + (this->width / 5), this->y + 55 + 75 + + 55 + 25, 50, (int)(this->width * 3) / 5, this->actualOption->second[0], PADDING, WrappableText::Style::BODY, WrappableText::TextAlign::CENTER, APP_COLORS().SECONDARY_DARK);
};