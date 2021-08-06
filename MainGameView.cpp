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
		* bgSprite = new Sprite(),
		* logoSprite = new Sprite(),
		* franjasSprite = new Sprite(),
		* xSprite = new Sprite();
	
	Vector2f
		logoScale,
		franjasScale,
		xScale;

	const Vector2f CENTER = Vector2f((float)(this->x + (this->width / 2)), (float)(this->y + (this->height / 2)));

	CircleShape
		* circle1 = new CircleShape(),
		* circle2 = new CircleShape(),
		* circle3 = new CircleShape();
	
	this->bg = new Texture();
	this->logo = new Texture();
	this->franjas = new Texture();
	this->xS = new Texture();
							 
	if (!this->logo->loadFromFile("resources\\images\\logo.png") || !this->bg->loadFromFile("resources\\images\\bg.png") || !this->franjas->loadFromFile("resources\\images\\franjas.png") || !this->xS->loadFromFile("resources\\images\\x.png"))
	{
		#ifdef _DEBUG
				Console().debug("Error loading image", "There was an error loading logo.png or bg.png", __LINE__, __FILE__, Console::Message_Type::ERR);
		#endif
	}

	logoScale = Vector2f((float)(logo->getSize().x * 0.2) / this->width, (float)(logo->getSize().x * 0.2) / this->width);
	franjasScale = Vector2f((float)(logo->getSize().x) / this->width, (float)(logo->getSize().x) / this->width);
	xScale = Vector2f((float)(logo->getSize().x) / this->width, (float)(logo->getSize().x) / this->width);

	// Creates the background circles for the strike's X
	circle1->setRadius(50);
	circle1->setFillColor(APP_COLORS().GRAY);
	circle1->setPosition((float)(CENTER.x - 50), (float)(this->height * 6 / 10));

	circle2->setRadius(50);
	circle2->setFillColor(APP_COLORS().GRAY);
	circle2->setPosition((float)(CENTER.x - 175), (float)(this->height * 6 / 10));

	circle3->setRadius(50);
	circle3->setFillColor(APP_COLORS().GRAY);
	circle3->setPosition((float)(CENTER.x + 75), (float)(this->height * 6 / 10));
	
	// Convert bg.png (from image -> texture -> sprite) to draw on canvas
	bg->setSmooth(true);
	bgSprite->setTexture(*bg);
	bgSprite->setScale((float)this->width / bg->getSize().x, (float)this->height / bg->getSize().y);

	// Convert franjas.png (from image -> texture -> sprite) to draw on canvas
	franjas->setSmooth(true);
	franjasSprite->setTexture(*franjas);
	franjasSprite->setScale((float)this->width / (franjas->getSize().x + 40), (float)this->height / franjas->getSize().y);
	franjasSprite->setPosition((float)17, 0);

	// Convert logo.png (from image -> texture -> sprite) to draw on canvas
	logo->setSmooth(true);
	logoSprite->setScale(logoScale);
	logoSprite->setTexture(*logo);
	logoSprite->setPosition((float)(this->width / 2) - (logo->getSize().x * (logoScale.x / 2.f)), (float)this->height * 4 / 5);

	// Convert x.png (from image -> texture -> sprite) to draw on canvas
	xS->setSmooth(true);
	xSprite->setScale(xScale);
	xSprite->setTexture(*xS);
	xSprite->setPosition((float)(this->width / 2) - (xS->getSize().x * (xScale.x / 2.f)), (float)(this->height * 6 / 10));

	this->drawables["bg"] = bgSprite;
	this->drawables["franjas"] = franjasSprite;
	this->drawables["xBg1"] = circle1;
	this->drawables["xBg2"] = circle2;
	this->drawables["xBg3"] = circle3;

	this->drawables["x1"] = xSprite;
	xSprite->setPosition((float)((this->width / 2) - (xS->getSize().x * (xScale.x / 2.f))) - 125, (float)(this->height * 6 / 10));
	this->drawables["x1"] = xSprite;

	this->drawables["logoImage"] = logoSprite;
	this->drawables["question"] = new WrappableText(this->parent, (int)this->x + (this->width / 2) - (int)(this->width * 2) / 10, 40, 55, (int)(this->width * 2) / 5, "Pregunta X", PADDING, WrappableText::Style::TITLE, WrappableText::TextAlign::CENTER, APP_COLORS().GRAY_LIGHT, APP_COLORS().PRIMARY);
};
