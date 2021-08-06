/************************************************//**
 * \file    WinnerView.cpp
 * \brief   Here are defined all methods from WinnerView class
***************************************************/

/**************************************************/
// Libraries

#include <SFML/Graphics.hpp>

#include "RoundedRectangle.h"

#include "Button.h"
#include "Settings.h"
#include "SlideableMenu.h"
#include "StorageController.h"
#include "UIElement.h"
#include "WrappableText.h"
#include "RoundedRectangle.h"
#include "WinnerView.h"

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

WinnerView::WinnerView(RenderWindow* parent, int x, int y, int height, int width, map<string, vector<map<string, string>>> teams, string game) : UIElement(parent, x, y, height, width)
{
	this->initDrawables();
};

/*****************************/
// Getters and setters methods

/*****************************/
// Medoths

void WinnerView::initDrawables()
{
	Sprite
		* bgSprite = new Sprite(),
		* logoSprite = new Sprite(),
		* franjasSprite = new Sprite();
	
	Vector2f
		logoScale,
		franjasScale;

	this->bg = new Texture();
	this->logo = new Texture();
	this->franjas = new Texture();

	if (!this->logo->loadFromFile("resources\\images\\logo.png") || !this->bg->loadFromFile("resources\\images\\bg.png") || !this->franjas->loadFromFile("resources\\images\\franjas.png"))
	{
		#ifdef _DEBUG
				Console().debug("Error loading image", "There was an error loading logo.png or bg.png", __LINE__, __FILE__, Console::Message_Type::ERR);
		#endif
	}

	logoScale = Vector2f((float)(this->logo->getSize().x * 0.3) / this->width, (float)(this->logo->getSize().x * 0.3) / this->width);
	franjasScale = Vector2f((float)(this->franjas->getSize().x) / this->width, (float)(this->franjas->getSize().x) / this->width);

	// Convert bg.png (from image -> texture -> sprite) to draw on canvas
	this->bg->setSmooth(true);
	bgSprite->setTexture(*(this->bg));
	bgSprite->setScale((float)this->width / this->bg->getSize().x, (float)this->height / this->bg->getSize().y);

	// Convert logo.png (from image -> texture -> sprite) to draw on canvas
	this->logo->setSmooth(true);
	logoSprite->setScale(logoScale);
	logoSprite->setTexture(*(this->logo));
	logoSprite->setPosition((float)(this->width / 2) - (this->logo->getSize().x * (logoScale.x / 2.f)), (float)(this->height * 4 / 5) - 100);

	// Convert franjas.png (from image -> texture -> sprite) to draw on canvas
	this->franjas->setSmooth(true);
	franjasSprite->setTexture(*(this->franjas));
	franjasSprite->setScale((float)this->width / (this->franjas->getSize().x), (float)this->height / this->franjas->getSize().y);
	franjasSprite->setPosition((float)(this->width / 2) - (this->franjas->getSize().x * (franjasScale.x / 2.f)), 0);

	//Drawables
	this->drawables["bg"] = bgSprite;
	this->drawables["logoImage"] = logoSprite;
	this->drawables["franjas"] = franjasSprite;
	this->drawables["winner"] = new WrappableText(this->parent, (int)this->x + (this->width / 2) - (int)(this->width * 3) / 10, 65, 120, (int)(this->width * 3) / 5, "¡GANADOR!", PADDING, WrappableText::Style::SCORE, WrappableText::TextAlign::CENTER, APP_COLORS().GRAY_LIGHT, APP_COLORS().ACCENT);
	this->drawables["winnerTeam"] = new WrappableText(this->parent, (int)this->x + (this->width / 2) - (int)(this->width * 2) / 10, (this->height * 2 / 5), 60, (int)(this->width * 2) / 5, "EQUIPO AZUL", PADDING, WrappableText::Style::TITLE, WrappableText::TextAlign::CENTER, APP_COLORS().GRAY_LIGHT, APP_COLORS().PRIMARY);
};
