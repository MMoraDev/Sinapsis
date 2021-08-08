/************************************************//**
 * \file    MainGameView.cpp
 * \brief   Here are defined all methods from MainGameView class
***************************************************/

/**************************************************/
// Libraries

#include <ctime>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "RoundedRectangle.h"

#include "Button.h"
#include "MainGameView.h"
#include "MainView.h"
#include "Settings.h"
#include "SlideableMenu.h"
#include "StorageController.h"
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
// Private

/*****************************/
// Methods

void MainGameView::loop()
{
	if (static_cast<WrappableText*>(this->drawables["zzAlertz"])->getIsVisible() && (clock() - this->startTime) / CLOCKS_PER_SEC >= 2)
	{
		static_cast<WrappableText*>(this->drawables["zzAlertz"])->setIsVisible(false);
	}

	if (static_cast<Button*>(this->drawables["strike"])->isClicked() && this->strikes <= 2)
	{
		Sprite* strike = static_cast<Sprite*>(this->drawables["x" + to_string(++(this->strikes))]);
		Color opacity = strike->getColor();
		opacity.a = 255;
		strike->setColor(opacity);

		static_cast<SlideableMenu*>(this->drawables["zavatar2"])->nextOption();
	}

	for (Button* answer : this->answers)
	{
		if (answer->isClicked())
		{
			answer->setText();
		}
	}
};

/**************************************************/
// Public

/*****************************/
// Constructor

MainGameView::MainGameView(RenderWindow* parent, int x, int y, int height, int width, map<string, vector<map<string, string>>> teams, string gameMode) : MainView(parent, x, y, height, width)
{
	this->teams = teams;
	this->gameMode = gameMode;
	this->scores[0] = 0;
	this->scores[1] = 0;
	this->strikes = 0;
	this->round = 1;
	this->questions = StorageController::readFile("resources\\data\\" + this->gameMode + ".csv");
	this->initDrawables();
	this->playRound();
};

/*****************************/
// Getters and setters methods

string MainGameView::getWinner() { return this->winner; };
void MainGameView::setWinner(string winner) { this->winner = winner; };

map<string, map<string, int>> MainGameView::getRandomQuestion()
{
	int num = generateRandomNumber(questions.size() - 1);
	map<string, map<string, int>>::iterator it = this->questions.begin();
	map<string, map<string, int>> answer = map<string, map<string, int>>();
	advance(it, num);
	answer[it->first] = it->second;
	this->questions.erase(it);

	return answer;
}

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
	Color opacity = Color();

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
	circle1->setPosition((float)(CENTER.x - 30), (float)(this->height * 6 / 10) + 10);

	circle2->setRadius(30);
	circle2->setFillColor(APP_COLORS().GRAY);
	circle2->setPosition((float)(CENTER.x - 155), (float)(this->height * 6 / 10) + 10);

	circle3->setRadius(30);
	circle3->setFillColor(APP_COLORS().GRAY);
	circle3->setPosition((float)(CENTER.x + 95), (float)(this->height * 6 / 10)+ 10);

	circle4->setRadius(18);
	circle4->setFillColor(APP_COLORS().ACCENT);
	circle4->setPosition((float)(CENTER.x - 325), (float)128);

	circle5->setRadius(18);
	circle5->setFillColor(APP_COLORS().ACCENT);
	circle5->setPosition((float)(CENTER.x - 325), (float)170);

	circle6->setRadius(18);
	circle6->setFillColor(APP_COLORS().ACCENT);
	circle6->setPosition((float)(CENTER.x - 325), (float)212);

	circle7->setRadius(18);
	circle7->setFillColor(APP_COLORS().ACCENT);
	circle7->setPosition((float)(CENTER.x - 325), (float)254);

	circle8->setRadius(18);
	circle8->setFillColor(APP_COLORS().ACCENT);
	circle8->setPosition((float)(CENTER.x - 325), (float)296);

	circle9->setRadius(18);
	circle9->setFillColor(APP_COLORS().ACCENT);
	circle9->setPosition((float)(CENTER.x - 325), (float)338);
	
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
	xSprite1->setPosition((float)((this->width / 2) - (this->xS->getSize().x * (xScale.x / 2.f))) - 125, (float)(this->height * 6 / 10));
	opacity = xSprite1->getColor();
	opacity.a = 0;
	xSprite1->setColor(opacity);

	xSprite2->setScale(xScale);
	xSprite2->setTexture(*(this->xS));
	xSprite2->setPosition((float)((this->width / 2) - (this->xS->getSize().x * (xScale.x / 2.f))), (float)(this->height * 6 / 10));
	opacity = xSprite2->getColor();
	opacity.a = 0;
	xSprite2->setColor(opacity);

	xSprite3->setScale(xScale);
	xSprite3->setTexture(*(this->xS));
	xSprite3->setPosition((float)((this->width / 2) - (this->xS->getSize().x * (xScale.x / 2.f))) + 125, (float)(this->height * 6 / 10));
	opacity = xSprite3->getColor();
	opacity.a = 0;
	xSprite3->setColor(opacity);

	//Drawables
	this->drawables["bg"] = bgSprite;
	this->drawables["franjas"] = franjasSprite;
	this->drawables["bg1"] = circle1;
	this->drawables["bg2"] = circle2;
	this->drawables["bg3"] = circle3;
	this->drawables["x1"] = xSprite1;
	this->drawables["x2"] = xSprite2;
	this->drawables["x3"] = xSprite3;
	this->drawables["ybg4"] = circle4;
	this->drawables["ybg5"] = circle5;
	this->drawables["ybg6"] = circle6;
	this->drawables["ybg7"] = circle7;
	this->drawables["ybg8"] = circle8;
	this->drawables["ybg9"] = circle9;
	this->drawables["ranswer1"] = new WrappableText(this->parent, (int)this->x + (this->width / 2) - (int)(this->width * 2) / 10 - 40, 128, 35, (int)(this->width * 2) / 5 + 80, "", PADDING, WrappableText::Style::BODY, WrappableText::TextAlign::LEFT, APP_COLORS().BLACK, APP_COLORS().WHITE, false, 0.0f, false, false);
	this->drawables["ranswer2"] = new WrappableText(this->parent, (int)this->x + (this->width / 2) - (int)(this->width * 2) / 10 - 40, 170, 35, (int)(this->width * 2) / 5 + 80, "", PADDING, WrappableText::Style::BODY, WrappableText::TextAlign::LEFT, APP_COLORS().BLACK, APP_COLORS().WHITE, false, 0.0f, false, false);
	this->drawables["ranswer3"] = new WrappableText(this->parent, (int)this->x + (this->width / 2) - (int)(this->width * 2) / 10 - 40, 212, 35, (int)(this->width * 2) / 5 + 80, "", PADDING, WrappableText::Style::BODY, WrappableText::TextAlign::LEFT, APP_COLORS().BLACK, APP_COLORS().WHITE, false, 0.0f, false, false);
	this->drawables["ranswer4"] = new WrappableText(this->parent, (int)this->x + (this->width / 2) - (int)(this->width * 2) / 10 - 40, 254, 35, (int)(this->width * 2) / 5 + 80, "", PADDING, WrappableText::Style::BODY, WrappableText::TextAlign::LEFT, APP_COLORS().BLACK, APP_COLORS().WHITE, false, 0.0f, false, false);
	this->drawables["ranswer5"] = new WrappableText(this->parent, (int)this->x + (this->width / 2) - (int)(this->width * 2) / 10 - 40, 296, 35, (int)(this->width * 2) / 5 + 80, "", PADDING, WrappableText::Style::BODY, WrappableText::TextAlign::LEFT, APP_COLORS().BLACK, APP_COLORS().WHITE, false, 0.0f, false, false);
	this->drawables["ranswer6"] = new WrappableText(this->parent, (int)this->x + (this->width / 2) - (int)(this->width * 2) / 10 - 40, 338, 35, (int)(this->width * 2) / 5 + 80, "", PADDING, WrappableText::Style::BODY, WrappableText::TextAlign::LEFT, APP_COLORS().BLACK, APP_COLORS().WHITE, false, 0.0f, false, false);
	this->drawables["zansButton1"] = new Button(this->parent, (int)this->x + (this->width / 2) - 362, (int)122, 35, 120, "?", APP_COLORS().WHITE, Color::Transparent, Color::Transparent);
	this->drawables["zansButton2"] = new Button(this->parent, (int)this->x + (this->width / 2) - 362, (int)164, 35, 120, "?", APP_COLORS().WHITE, Color::Transparent, Color::Transparent);
	this->drawables["zansButton3"] = new Button(this->parent, (int)this->x + (this->width / 2) - 362, (int)206, 35, 120, "?", APP_COLORS().WHITE, Color::Transparent, Color::Transparent);
	this->drawables["zansButton4"] = new Button(this->parent, (int)this->x + (this->width / 2) - 362, (int)248, 35, 120, "?", APP_COLORS().WHITE, Color::Transparent, Color::Transparent);
	this->drawables["zansButton5"] = new Button(this->parent, (int)this->x + (this->width / 2) - 362, (int)290, 35, 120, "?", APP_COLORS().WHITE, Color::Transparent, Color::Transparent);
	this->drawables["zansButton6"] = new Button(this->parent, (int)this->x + (this->width / 2) - 362, (int)332, 35, 120, "?", APP_COLORS().WHITE, Color::Transparent, Color::Transparent);
	this->drawables["strike"] = new Button(this->parent, (int)this->x + (this->width / 2) - 160, (int)(this->height * 4 / 5) - 20, 55, 320, "Respuesta Incorrecta", APP_COLORS().GRAY_LIGHT, APP_COLORS().RED_DARK, APP_COLORS().RED);
	this->drawables["logoImage"] = logoSprite;
	this->drawables["zavatar1"] = new SlideableMenu(this->parent, (int)(this->width * 1 / 20) - 160, (int)(this->height * 3 / 10) + 60, 40, (int)(this->width * 2) / 5, this->dataToSlideableMenuFormat(this->teams["team1Players"]), "resources\\images\\avatars\\", false, true);
	this->drawables["zavatar2"] = new SlideableMenu(this->parent, (int)(this->width * 16 / 20) - 140, (int)(this->height * 3 / 10) + 60, 40, (int)(this->width * 2) / 5, this->dataToSlideableMenuFormat(this->teams["team2Players"]), "resources\\images\\avatars\\", false, true);
	this->drawables["qauestionsBg"] = new RoundedRectangle(this->parent, this->x + (this->width / 2) - 350, 90.5, 300, 700, BORDER_RADIUS, APP_COLORS().WHITE);
	this->drawables["qauestionsaBg"] = new RoundedRectangle(this->parent, this->x + (this->width / 2) - 345, 95.5, 290, 690, BORDER_RADIUS, APP_COLORS().GRAY_LIGHT);
	this->drawables["question"] = new WrappableText(this->parent, (int)this->x + (this->width / 2) - (int)(this->width * 2) / 10, 45, 75, (int)(this->width * 2) / 5, "", PADDING, WrappableText::Style::QUESTION, WrappableText::TextAlign::CENTER, APP_COLORS().GRAY_LIGHT, APP_COLORS().PRIMARY);
	this->drawables["leftTeam"] = new WrappableText(this->parent, (int)this->x + (this->width * 1 / 40) + 10, 5, 45, (int)(this->width * 1) / 5 + 20, this->teams["names"][0]["team1"], PADDING, WrappableText::Style::SUBTITLE, WrappableText::TextAlign::LEFT, APP_COLORS().GRAY_LIGHT, APP_COLORS().GRAY_LIGHT ,true);
	this->drawables["rightTeam"] = new WrappableText(this->parent, (int)this->x + (this->width * 39 / 40) - (this->width * 1) / 5 - 10, 5, 45, (int)(this->width * 1) / 5 + 2, this->teams["names"][0]["team2"], PADDING, WrappableText::Style::SUBTITLE, WrappableText::TextAlign::RIGHT, APP_COLORS().GRAY_LIGHT, APP_COLORS().GRAY_LIGHT, true);
	this->drawables["leftTeamScore"] = new WrappableText(this->parent, (int)this->x + (this->width * 1 / 40) - 15, 45, 45, (int)(this->width * 1) / 5 + 20, to_string(this->scores[0]), PADDING, WrappableText::Style::SCORE, WrappableText::TextAlign::LEFT, APP_COLORS().GRAY_LIGHT, Color::Transparent);
	this->drawables["rightTeamScore"] = new WrappableText(this->parent, (int)this->x + (this->width * 39 / 40) - (this->width * 1) / 5 + 5, 45, 45, (int)(this->width * 1) / 5 + 2, to_string(this->scores[1]), PADDING, WrappableText::Style::SCORE, WrappableText::TextAlign::RIGHT, APP_COLORS().GRAY_LIGHT, Color::Transparent);
	this->drawables["zzAlertz"] = new WrappableText(this->parent, (int)this->x + (this->width / 2) - (int)(this->width * 4) / 10, (int)this->y + (this->height / 2) - 50, 120, (int)(this->width * 4) / 5, "ROUND 1", PADDING, WrappableText::Style::SCORE, WrappableText::TextAlign::CENTER, APP_COLORS().GRAY_LIGHT, APP_COLORS().ACCENT, false, 0.0F, false, false);

	this->answers.push_back(static_cast<Button*>(this->drawables["zansButton1"]));
	this->answers.push_back(static_cast<Button*>(this->drawables["zansButton2"]));
	this->answers.push_back(static_cast<Button*>(this->drawables["zansButton3"]));
	this->answers.push_back(static_cast<Button*>(this->drawables["zansButton4"]));
	this->answers.push_back(static_cast<Button*>(this->drawables["zansButton5"]));
	this->answers.push_back(static_cast<Button*>(this->drawables["zansButton6"]));
};

int MainGameView::generateRandomNumber(int max, int min)
{
	srand(time(NULL));

	return rand() % max + min;
};

void MainGameView::playRound()
{
	short int 
		answerNum = 0,
		playingTeam = this->generateRandomNumber(1);
	this->strikes = 0;
	this->round++;

	if (this->round <= 3)
	{
		for (int i = 0; i < 3; i++)
		{
			Sprite* strike = static_cast<Sprite*>(this->drawables["x" + to_string(i + 1)]);
			Color opacity = strike->getColor();
			opacity.a = 0;
			strike->setColor(opacity);
		}

		static_cast<WrappableText*>(this->drawables["zzAlertz"])->setText("Ronda" + to_string(this->round));
		static_cast<WrappableText*>(this->drawables["zzAlertz"])->setIsVisible(true);
		this->startTime = clock();

		this->actualQuestion = getRandomQuestion();
		map<string, int>::iterator i = this->actualQuestion[this->actualQuestion.begin()->first].begin();
		string question = this->actualQuestion.begin()->first;
		static_cast<WrappableText*>(this->drawables["question"])->setText(question);

		while (i != this->actualQuestion[this->actualQuestion.begin()->first].end())
		{
			static_cast<WrappableText*>(this->drawables["ranswer" + to_string(++answerNum)])->setText(i->first);
			i++;
		}
	}
	else
	{
		if (this->scores[0] > this->scores[1])
		{
			this->winner = this->teams["names"][0]["team1"];
		}
		else if (this->scores[0] < this->scores[1])
		{
			this->winner = this->teams["names"][0]["team2"];
		}
		else
		{
			this->winner = "Empate";
		}
	}
};


