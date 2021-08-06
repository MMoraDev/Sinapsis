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
	Sprite
		* bgSprite = new Sprite(),
		* addPlayerSprite = new Sprite(),
		* addPlayerSprite2 = new Sprite(),
		* vsSprite = new Sprite();
	
	Vector2f
		logoScale;

	map<string, vector<string>> avatars = map<string, vector<string>>();

	this->bg = new Texture();
	this->addPlayer = new Texture();
	this->vs = new Texture();

	if (!this->bg->loadFromFile("resources\\images\\bg.png") || !this->addPlayer->loadFromFile("resources\\images\\add.png") || !this->vs->loadFromFile("resources\\images\\vs.png"))
	{
		#ifdef _DEBUG
				Console().debug("Error loading image", "There was an error loading logo.png or bg.png", __LINE__, __FILE__, Console::Message_Type::ERR);
		#endif
	}

	logoScale = Vector2f((float)(this->addPlayer->getSize().x * 0.45) / this->width, (float)(this->addPlayer->getSize().x * 0.45) / this->width);

	avatars["avatars"] = StorageController::getFilesNames(AVATARS_PATH);

	// Convert bg.png (from image -> texture -> sprite) to draw on canvas
	this->bg->setSmooth(true);
	bgSprite->setTexture(*(this->bg));
	bgSprite->setScale((float)this->width / this->bg->getSize().x, (float)this->height / this->bg->getSize().y);

	// Convert vs.png (from image -> texture -> sprite) to draw on canvas
	this->vs->setSmooth(true);
	vsSprite->setScale(logoScale);
	vsSprite->setTexture(*(this->vs));
	vsSprite->setPosition((float)(this->width / 2) - (this->vs->getSize().x * (logoScale.x / 2.f)), (float)(this->height / 2) - (this->vs->getSize().x * (logoScale.x / 2.f)));

	// Convert add.png (from image -> texture -> sprite) to draw on canvas
	this->addPlayer->setSmooth(true);
	addPlayerSprite->setScale(logoScale);
	addPlayerSprite->setTexture(*(this->addPlayer));
	addPlayerSprite->setPosition((float)this->x + (this->width / 5) + 100, (float)this->y + 108);

	addPlayerSprite2->setScale(logoScale);
	addPlayerSprite2->setTexture(*(this->addPlayer));
	addPlayerSprite2->setPosition((float)this->x + (this->width * 4 / 5) + 20, (float)this->y + 108);

	this->drawables["title"] = new WrappableText(this->parent, (int)this->x + (this->width / 2) - (int)(this->width * 2) / 10, 15, 55, (int)(this->width * 2) / 5, "Registro de Jugadores", PADDING, WrappableText::Style::TITLE, WrappableText::TextAlign::CENTER, APP_COLORS().GRAY_LIGHT, APP_COLORS().PRIMARY);
	
	this->drawables["team1"] = new TextField(this->parent, (int)this->x + (this->width * 1 / 20) - 20, 65, 50, (int)(this->width * 2) / 5, "Equipo azul", PADDING, WrappableText::Style::TITLE, WrappableText::TextAlign::LEFT, APP_COLORS().ACCENT, APP_COLORS().ACCENT);
	this->drawables["team2"] = new TextField(this->parent, (int)this->x + (this->width * 19 / 20) - (this->width * 2) / 5 + 20, 65, 50, (int)(this->width * 2) / 5, "Equipo azul", PADDING, WrappableText::Style::TITLE, WrappableText::TextAlign::RIGHT, APP_COLORS().ACCENT, APP_COLORS().ACCENT);
	
	this->drawables["sm1"] = new SlideableMenu(this->parent, (int)this->x + (this->width * 1 / 20), this->y + 50, 320, 200, avatars, "resources\\images\\avatars\\", true);
	this->drawables["zaddPlayer"] = addPlayerSprite;
	/*this->drawables["sm2"] = new SlideableMenu(this->parent, (int)this->x + (this->width * 1 / 20), this->y + 220, 320, 200, avatars, "resources\\images\\avatars\\", true);
	this->drawables["sm3"] = new SlideableMenu(this->parent, (int)this->x + (this->width * 1 / 20), this->y + 390, 320, 200, avatars, "resources\\images\\avatars\\", true);
	this->drawables["sm4"] = new SlideableMenu(this->parent, (int)this->x + (this->width / 5) + 60, this->y + 50, 320, 200, avatars, "resources\\images\\avatars\\", true);
	this->drawables["sm5"] = new SlideableMenu(this->parent, (int)this->x + (this->width / 5) + 60, this->y + 220, 320, 200, avatars, "resources\\images\\avatars\\", true);
	this->drawables["sm6"] = new SlideableMenu(this->parent, (int)this->x + (this->width / 5) + 60, this->y + 390, 320, 200, avatars, "resources\\images\\avatars\\", true);

	*/this->drawables["sm7"] = new SlideableMenu(this->parent, (int)this->x + (this->width * 11 / 20) + 40, this->y + 50, 320, 200, avatars, "resources\\images\\avatars\\", true);
	this->drawables["zaddPlayer2"] = addPlayerSprite2;
	/*this->drawables["sm8"] = new SlideableMenu(this->parent, (int)this->x + (this->width * 11 / 20) + 40, this->y + 220, 320, 200, avatars, "resources\\images\\avatars\\", true);
	this->drawables["sm9"] = new SlideableMenu(this->parent, (int)this->x + (this->width * 11 / 20) + 40, this->y + 390, 320, 200, avatars, "resources\\images\\avatars\\", true);
	this->drawables["sm10"] = new SlideableMenu(this->parent, (int)this->x + (this->width * 4 / 5) - 20, this->y + 50, 320, 200, avatars, "resources\\images\\avatars\\", true);
	this->drawables["sm11"] = new SlideableMenu(this->parent, (int)this->x + (this->width * 4 / 5) - 20, this->y + 220, 320, 200, avatars, "resources\\images\\avatars\\", true);
	this->drawables["sm12"] = new SlideableMenu(this->parent, (int)this->x + (this->width * 4 / 5) - 20, this->y + 390, 320, 200, avatars, "resources\\images\\avatars\\", true);*/
	
	this->drawables["bg"] = bgSprite;
	this->drawables["vs"] = vsSprite;

	this->textFields.push_back(static_cast<TextField*>(this->drawables["team1"]));
	this->textFields.push_back(static_cast<TextField*>(this->drawables["team2"]));
	this->avatars.push_back(static_cast<SlideableMenu*>(this->drawables["sm1"]));
	//this->avatars.push_back(static_cast<SlideableMenu*>(this->drawables["sm2"]));
};
