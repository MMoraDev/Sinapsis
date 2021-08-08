/************************************************//**
 * \file    WinnerView.cpp
 * \brief   Here are defined all methods from WinnerView class
***************************************************/

/**************************************************/
// Libraries

#include <SFML/Graphics.hpp>

#include "RoundedRectangle.h"

#include "Button.h"
#include "MainView.h"
#include "Settings.h"
#include "SlideableMenu.h"
#include "StorageController.h"
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
// Private

/*****************************/
// Medoths
void WinnerView::loop()
{
	if (static_cast<Button*>(this->drawables["goToMenu"])->isClicked())
	{
		this->isDone = true;
	}
};

/**************************************************/
// Public

/*****************************/
// Constructor

WinnerView::WinnerView(RenderWindow* parent, int x, int y, int height, int width, string winner) : MainView(parent, x, y, height, width)
{
	this->isDone = false;
	this->initDrawables();
};

/*****************************/
// Getters and setters methods
bool WinnerView::getIsDone() { return this->isDone; };
void WinnerView::setIsDone(bool isDone) { this->isDone = isDone; };

/*****************************/
// Medoths

void WinnerView::initDrawables()
{
	Sprite
		* bgSprite = new Sprite(),
		* logoSprite = new Sprite(),
		* franja1Sprite = new Sprite(),
		* franja2Sprite = new Sprite();
	
	Vector2f
		logoScale,
		franjasScale;

	this->bg = new Texture();
	this->logo = new Texture();
	this->franjaIzq = new Texture();
	this->franjaDer = new Texture();

	if (!this->logo->loadFromFile("resources\\images\\logo.png") || !this->bg->loadFromFile("resources\\images\\bg.png") || !this->franjaIzq->loadFromFile("resources\\images\\franjaIzq.png") || !this->franjaDer->loadFromFile("resources\\images\\franjaDer.png"))
	{
		#ifdef _DEBUG
				Console().debug("Error loading image", "There was an error loading logo.png or bg.png", __LINE__, __FILE__, Console::Message_Type::ERR);
		#endif
	}

	logoScale = Vector2f((float)(this->logo->getSize().x * 0.3) / this->width, (float)(this->logo->getSize().x * 0.3) / this->width);
	franjasScale = Vector2f((float)(this->franjaIzq->getSize().x * 3 / this->width), (float)(this->franjaIzq->getSize().x * 3) / this->width);

	// Convert bg.png (from image -> texture -> sprite) to draw on canvas
	this->bg->setSmooth(true);
	bgSprite->setTexture(*(this->bg));
	bgSprite->setScale((float)this->width / this->bg->getSize().x, (float)this->height / this->bg->getSize().y);

	// Convert logo.png (from image -> texture -> sprite) to draw on canvas
	this->logo->setSmooth(true);
	logoSprite->setScale(logoScale);
	logoSprite->setTexture(*(this->logo));
	logoSprite->setPosition((float)(this->width / 2) - (this->logo->getSize().x * (logoScale.x / 2.f)), (float)(this->height * 3 / 5));

	// Convert franjas.png (from image -> texture -> sprite) to draw on canvas
	this->franjaIzq->setSmooth(true);
	franja1Sprite->setScale(franjasScale);
	franja1Sprite->setTexture(*(this->franjaIzq));
	franja1Sprite->setPosition(- 200, 0);

	this->franjaDer->setSmooth(true);
	franja2Sprite->setScale(franjasScale);
	franja2Sprite->setTexture(*(this->franjaDer));
	franja2Sprite->setPosition((float)(this->width) - (this->franjaDer->getSize().x * (franjasScale.x / 2.f)), 0);

	//Drawables
	this->drawables["bg"] = bgSprite;
	this->drawables["logoImage"] = logoSprite;
	this->drawables["franjaIzq"] = franja1Sprite;
	this->drawables["franjaDer"] = franja2Sprite;
	this->drawables["winner"] = new WrappableText(this->parent, (int)this->x + (this->width / 2) - (int)(this->width * 3) / 10, 65, 120, (int)(this->width * 3) / 5, "¡GANADOR!", PADDING, WrappableText::Style::SCORE, WrappableText::TextAlign::CENTER, APP_COLORS().GRAY_LIGHT, APP_COLORS().ACCENT);
	this->drawables["winnerTeam"] = new WrappableText(this->parent, (int)this->x + (this->width / 2) - (int)(this->width * 2) / 10, (this->height * 2 / 5), 60, (int)(this->width * 2) / 5, this->winner, PADDING, WrappableText::Style::TITLE, WrappableText::TextAlign::CENTER, APP_COLORS().GRAY_LIGHT, APP_COLORS().PRIMARY);
	this->drawables["goToMenu"] = new Button(this->parent, (int)this->x + (this->width / 2) - 150, (int)(this->height * 4 / 5) + 40, 55, 300, "Volver al Menú", APP_COLORS().GRAY_LIGHT, APP_COLORS().ACCENT, APP_COLORS().BLACK);
};
