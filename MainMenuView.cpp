/************************************************//**
 * \file    MainMenuView.cpp
 * \brief   Here are defined all methods from MainMenuView class
***************************************************/

/**************************************************/
// Libraries

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Button.h"
#include "MainMenuView.h"
#include "MainView.h"
#include "RoundedRectangle.h"
#include "Settings.h"
#include "SlideableMenu.h"
#include "StorageController.h"

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

void MainMenuView::loop()
{
	this->selectedOption = static_cast<SlideableMenu*>(this->drawables["mainMenu"])->getSelectedOption();
};

/**************************************************/
// Public

/*****************************/
// Constructor

MainMenuView::MainMenuView(RenderWindow* parent, int x, int y, int height, int width) : MainView(parent, x, y, height, width)
{
	this->initDrawables();
};

/*****************************/
// Getters and setters methods

map<string, string> MainMenuView::getSelectedOption() { return this->selectedOption; };
void MainMenuView::setSelectedOption(map<string, string> option) { this->selectedOption = option; };

/*****************************/
// Medoths

void MainMenuView::initDrawables()
{
	Sprite 
		*bgSprite = new Sprite(), 
		*logoSprite = new Sprite();
	Vector2f logoScale;

	options["Modo de juego"] = StorageController::getFilesNames(DATA_PATH);
	this->logo = new Texture();
	this->bg = new Texture();

	if (!this->logo->loadFromFile("resources\\images\\logo.png") || !this->bg->loadFromFile("resources\\images\\bg.png"))
	{
		#ifdef _DEBUG
			Console().debug("Error loading image", "There was an error loading logo.png or bg.png", __LINE__, __FILE__, Console::Message_Type::ERR);
		#endif
	}

	logoScale = Vector2f((float)(logo->getSize().x * 0.7) / this->width, (float)(logo->getSize().x * 0.7) / this->width);

	// Convert bg.png (from image -> texture -> sprite) to draw on canvas
	bg->setSmooth(true);
	bgSprite->setTexture(*bg);
	bgSprite->setScale((float)this->width / bg->getSize().x, (float)this->height / bg->getSize().y);

	this->drawables["bg"] = bgSprite;

	// Convert logo.png (from image -> texture -> sprite) to draw on canvas
	logo->setSmooth(true);
	logoSprite->setScale(logoScale);
	logoSprite->setTexture(*logo);
	logoSprite->setPosition((float)(this->width / 2) - (logo->getSize().x * (logoScale.x / 2.f)), (float)this->height / 15);
	
	this->drawables["logoImage"] = logoSprite;

	this->drawables["mainMenu"] = new SlideableMenu(this->parent, (int)(this->width / 2) - (400 / 2), (int)(this->height * (1 + 0.1))/ 2, 40, 400, this->options, "resources\\images\\");
};
