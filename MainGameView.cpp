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
#include "RoundedRectangle.h"

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

MainGameView::MainGameView(RenderWindow* parent, int x, int y, int height, int width, map<string, vector<map<string, string>>> teams, string game) : UIElement(parent, x, y, height, width)
{
	this->teams = teams;
	this->game = game;
	this->initDrawables();
};

/*****************************/
// Getters and setters methods

/*****************************/
// Medoths

map<string, vector<string>> MainGameView::dataToSlideableMenuFormat(vector<map<string, string>> players)
{
	map<string, vector<string>> res = map<string, vector<string>>();

	for (map<string, string> player : players)
	{
		res[player["text"]] = { player["image"] };
	}

	return res;
};

void MainGameView::initDrawables()
{
	Sprite
		* bgSprite = new Sprite(),
		* logoSprite = new Sprite(),
		* franjasSprite = new Sprite(),
		* xSprite1 = new Sprite(),
		* xSprite2 = new Sprite(),
		* xSprite3 = new Sprite();
	
	Vector2f
		logoScale,
		franjasScale,
		xScale;

	const Vector2f CENTER = Vector2f((float)(this->x + (this->width / 2)), (float)(this->y + (this->height / 2)));

	CircleShape
		* circle1 = new CircleShape(),
		* circle2 = new CircleShape(),
		* circle3 = new CircleShape(),
		* circle4 = new CircleShape(),
		* circle5 = new CircleShape(),
		* circle6 = new CircleShape(),
		* circle7 = new CircleShape(),
		* circle8 = new CircleShape(),
		* circle9 = new CircleShape();
	
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

	logoScale = Vector2f((float)(this->logo->getSize().x * 0.15) / this->width, (float)(this->logo->getSize().x * 0.15) / this->width);
	franjasScale = Vector2f((float)(this->logo->getSize().x) / this->width, (float)(this->logo->getSize().x) / this->width);
	xScale = Vector2f((float)(this->logo->getSize().x) / this->width, (float)(this->logo->getSize().x) / this->width);

	// Creates the background circles for the strike's X
	circle1->setRadius(30);
	circle1->setFillColor(APP_COLORS().GRAY);
	circle1->setPosition((float)(CENTER.x - 30), (float)(this->height * 6 / 10) + 40);

	circle2->setRadius(30);
	circle2->setFillColor(APP_COLORS().GRAY);
	circle2->setPosition((float)(CENTER.x - 155), (float)(this->height * 6 / 10) + 40);

	circle3->setRadius(30);
	circle3->setFillColor(APP_COLORS().GRAY);
	circle3->setPosition((float)(CENTER.x + 95), (float)(this->height * 6 / 10)+ 40);

	circle4->setRadius(10);
	circle4->setFillColor(APP_COLORS().ACCENT);
	circle4->setPosition((float)(CENTER.x - 335), (float)105.5);

	circle5->setRadius(10);
	circle5->setFillColor(APP_COLORS().ACCENT);
	circle5->setPosition((float)(CENTER.x - 335), (float)145.5);

	circle6->setRadius(10);
	circle6->setFillColor(APP_COLORS().ACCENT);
	circle6->setPosition((float)(CENTER.x - 335), (float)185.5);
	
	// Convert bg.png (from image -> texture -> sprite) to draw on canvas
	this->bg->setSmooth(true);
	bgSprite->setTexture(*(this->bg));
	bgSprite->setScale((float)this->width / this->bg->getSize().x, (float)this->height / this->bg->getSize().y);

	// Convert franjas.png (from image -> texture -> sprite) to draw on canvas
	this->franjas->setSmooth(true);
	franjasSprite->setTexture(*(this->franjas));
	franjasSprite->setScale((float)this->width / (this->franjas->getSize().x + 40), (float)this->height / this->franjas->getSize().y);
	franjasSprite->setPosition((float)17, 0);

	// Convert logo.png (from image -> texture -> sprite) to draw on canvas
	this->logo->setSmooth(true);
	logoSprite->setScale(logoScale);
	logoSprite->setTexture(*(this->logo));
	logoSprite->setPosition((float)(this->width / 2) - (this->logo->getSize().x * (logoScale.x / 2.f)), (float)(this->height * 4 / 5) + 50);

	// Convert x.png (from image -> texture -> sprite) to draw on canvas
	this->xS->setSmooth(true);

	xSprite1->setScale(xScale);
	xSprite1->setTexture(*(this->xS));
	xSprite1->setPosition((float)((this->width / 2) - (this->xS->getSize().x * (xScale.x / 2.f))) - 125, (float)(this->height * 6 / 10) + 28);

	xSprite2->setScale(xScale);
	xSprite2->setTexture(*(this->xS));
	xSprite2->setPosition((float)((this->width / 2) - (this->xS->getSize().x * (xScale.x / 2.f))), (float)(this->height * 6 / 10) + 28);

	xSprite3->setScale(xScale);
	xSprite3->setTexture(*(this->xS));
	xSprite3->setPosition((float)((this->width / 2) - (this->xS->getSize().x * (xScale.x / 2.f))) + 125, (float)(this->height * 6 / 10) + 28);

	//Drawables
	this->drawables["bg"] = bgSprite;
	this->drawables["franjas"] = franjasSprite;
	this->drawables["bg1"] = circle1;
	this->drawables["bg2"] = circle2;
	this->drawables["bg3"] = circle3;
	this->drawables["x1"] = xSprite1;
	this->drawables["x2"] = xSprite2;
	this->drawables["x3"] = xSprite3;
	this->drawables["xBg1"] = circle1;
	this->drawables["xBg2"] = circle2;
	this->drawables["xBg3"] = circle3;
	this->drawables["xa1"] = xSprite1;
	this->drawables["xa2"] = xSprite2;
	this->drawables["xa3"] = xSprite3;
	this->drawables["logoImage"] = logoSprite;
	this->drawables["zavatar1"] = new SlideableMenu(this->parent, (int)(this->width * 1 / 20) - 100, (int)(this->height * 5 / 10), 40, (int)(this->width * 2) / 5, this->dataToSlideableMenuFormat(this->teams["team1Players"]), "resources\\images\\avatars\\", false, true);
	this->drawables["zavatar2"] = new SlideableMenu(this->parent, (int)(this->width * 16 / 20) - 200, (int)(this->height * 5 / 10), 40, (int)(this->width * 2) / 5, this->dataToSlideableMenuFormat(this->teams["team2Players"]), "resources\\images\\avatars\\", false, true);
	this->drawables["question"] = new WrappableText(this->parent, (int)this->x + (this->width / 2) - (int)(this->width * 2) / 10, 65, 55, (int)(this->width * 2) / 5, "Pregunta X", PADDING, WrappableText::Style::TITLE, WrappableText::TextAlign::CENTER, APP_COLORS().GRAY_LIGHT, APP_COLORS().PRIMARY);
	this->drawables["qauestionsBg"] = new RoundedRectangle(this->parent, this->x + (this->width / 2) - 350, 90.5, 300, 700, BORDER_RADIUS, APP_COLORS().WHITE);
	this->drawables["qauestionsaBg"] = new RoundedRectangle(this->parent, this->x + (this->width / 2) - 345, 95.5, 290, 690, BORDER_RADIUS, APP_COLORS().GRAY_LIGHT);
	this->drawables["leftTeam"] = new WrappableText(this->parent, (int)this->x + (this->width * 1 / 40) + 10, 5, 45, (int)(this->width * 1) / 5 + 20, this->teams["names"][0]["team1"], PADDING, WrappableText::Style::SUBTITLE, WrappableText::TextAlign::LEFT, APP_COLORS().GRAY_LIGHT, APP_COLORS().GRAY_LIGHT ,true);
	this->drawables["rightTeam"] = new WrappableText(this->parent, (int)this->x + (this->width * 39 / 40) - (this->width * 1) / 5 - 10, 5, 45, (int)(this->width * 1) / 5 + 2, this->teams["names"][0]["team2"], PADDING, WrappableText::Style::SUBTITLE, WrappableText::TextAlign::RIGHT, APP_COLORS().GRAY_LIGHT, APP_COLORS().GRAY_LIGHT, true);
	this->drawables["leftTeamScore"] = new WrappableText(this->parent, (int)this->x + (this->width * 1 / 40) - 15, 45, 45, (int)(this->width * 1) / 5 + 20, to_string(this->scores[0]), PADDING, WrappableText::Style::SCORE, WrappableText::TextAlign::LEFT, APP_COLORS().GRAY_LIGHT, Color::Transparent);
	this->drawables["rightTeamScore"] = new WrappableText(this->parent, (int)this->x + (this->width * 39 / 40) - (this->width * 1) / 5 + 5, 45, 45, (int)(this->width * 1) / 5 + 2, to_string(this->scores[1]), PADDING, WrappableText::Style::SCORE, WrappableText::TextAlign::RIGHT, APP_COLORS().GRAY_LIGHT, Color::Transparent);
};
