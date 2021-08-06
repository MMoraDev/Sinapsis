/************************************************//**
 * \file    SignUpView.cpp
 * \brief   Here are defined all methods from SignUpView class
***************************************************/

/**************************************************/
// Libraries

#include <SFML/Graphics.hpp>

#include "RoundedRectangle.h"

#include "Button.h"
#include "Settings.h"
#include "SlideableMenu.h"
#include "StorageController.h"
#include "SignUpView.h"
#include "TextField.h"
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
// Private

/*****************************/
// Medoths

void SignUpView::loop()
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		this->selectedTextField = NULL;
	}
	
	for (TextField* field : this->textFields)
	{
		if (field->isMouseOver() && Mouse::isButtonPressed(Mouse::Left))
			this->selectedTextField = field;
	}

	for (SlideableMenu* avatar : this->avatars)
	{
		if (avatar->isMouseOver() && Mouse::isButtonPressed(Mouse::Left))
			this->selectedTextField = avatar->getTextFieldPtr();
	}
};

/**************************************************/
// Public

/*****************************/
// Constructor

SignUpView::SignUpView(RenderWindow* parent, int x, int y, int height, int width) : UIElement(parent, x, y, height, width)
{
	this->initDrawables();
};

/*****************************/
// Getters and setters methods

/*****************************/
// Medoths

void SignUpView::changeSelectedTextField(String input)
{
	if (this->selectedTextField != NULL)
	{
		if (input == '\b')
			this->selectedTextField->setText(this->selectedTextField->getText().substr(0, this->selectedTextField->getText().size() - 1));
		else
			this->selectedTextField->setText(this->selectedTextField->getText() + input);
	}
};


void SignUpView::initDrawables()
{
	Sprite * bgSprite = new Sprite();
	map<string, vector<string>> avatars = map<string, vector<string>>();

	this->bg = new Texture();

	if (!this->bg->loadFromFile("resources\\images\\bg.png"))
	{
		#ifdef _DEBUG
				Console().debug("Error loading image", "There was an error loading logo.png or bg.png", __LINE__, __FILE__, Console::Message_Type::ERR);
		#endif
	}

	avatars["avatars"] = StorageController::getFilesNames(AVATARS_PATH);

	// Convert bg.png (from image -> texture -> sprite) to draw on canvas
	this->bg->setSmooth(true);
	bgSprite->setTexture(*(this->bg));
	bgSprite->setScale((float)this->width / this->bg->getSize().x, (float)this->height / this->bg->getSize().y);

	this->drawables["team1"] = new TextField(this->parent, (int)this->x + (this->width / 5), this->y, 50, (int)(this->width * 3) / 5, "Equipo azul", PADDING, WrappableText::Style::TITLE, WrappableText::TextAlign::LEFT, APP_COLORS().PRIMARY, APP_COLORS().PRIMARY);
	this->drawables["team2"] = new TextField(this->parent, (int)this->x + (this->width / 5), this->y + 50, 50, (int)(this->width * 3) / 5, "Equipo azul", PADDING, WrappableText::Style::TITLE, WrappableText::TextAlign::LEFT, APP_COLORS().PRIMARY, APP_COLORS().PRIMARY);
	this->drawables["sm1"] = new SlideableMenu(this->parent, (int)this->x + (this->width / 5), this->y + 100, 100, 200, avatars, "resources\\images\\avatars\\", true);
	this->drawables["sm2"] = new SlideableMenu(this->parent, (int)this->x + (this->width / 5), this->y + 300, 100, 200, avatars, "resources\\images\\avatars\\", true);
	this->drawables["bg"] = bgSprite;

	this->textFields.push_back(static_cast<TextField*>(this->drawables["team1"]));
	this->textFields.push_back(static_cast<TextField*>(this->drawables["team2"]));
	this->avatars.push_back(static_cast<SlideableMenu*>(this->drawables["sm1"]));
	this->avatars.push_back(static_cast<SlideableMenu*>(this->drawables["sm2"]));
};
