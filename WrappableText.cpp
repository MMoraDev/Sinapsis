/************************************************//**
 * \file    WrappableText.cpp
 * \brief   Here are defined all methods from WrappableText class
***************************************************/

/**************************************************/
// Libraries

#include <iostream>
#include <SFML/Graphics.hpp>

#include "RoundedRectangle.h"
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
// Static variables

vector<Font*> WrappableText::fonts = vector<Font*>();
bool WrappableText::initialized = false;

/**************************************************/
// Public

/*****************************/
// Constructor

WrappableText::WrappableText(RenderWindow* parent, int x, int y, int height, int width, string text, Vector2f padding, Style style, TextAlign alignment, Color fontColor, Color bgColor, bool isUnderlined, float borderRadius, bool isClickable) : UIElement(parent, x, y, height, width, isClickable)
{
	this->text = text;
	this->padding = padding;
	this->style = style;
	this->alignment = alignment;
	this->fontColor = fontColor;
	this->bgColor = bgColor;
	this->isUnderlined = isUnderlined;
	this->borderRadius = borderRadius;
	this->isClickable = isClickable;

	if (!WrappableText::initialized)
	{
		WrappableText::initialized = true;

		for (string fontWeight : this->FontWeight)
		{
			Font* tempFont = new Font();
			if (!tempFont->loadFromFile("resources\\fonts\\MPLUSRounded1c-" + fontWeight + ".ttf"))
			{
				#ifdef _DEBUG
					Console().debug("Error loading font", "There was an error loading MPLUSRounded1c" + fontWeight + ".ttf", __LINE__, __FILE__, Console::Message_Type::ERR);
				#endif
			}

			WrappableText::fonts.push_back(tempFont);
		}
	}

	this->initDrawables();
};

/********************/
// Getters and setters methods

string WrappableText::getText() { return this->text; };
void WrappableText::setText(string text)
{
	this->text = text;
	this->initDrawables();
};

/*****************************/
// Medoths

void WrappableText::addLeftSpaces(string& line)
{
	this->uiText->setString(" ");
	float charWidth = uiText->getLocalBounds().width;
	this->uiText->setString(line);
	float remainingWidth = this->width - (this->padding.x * 2) - uiText->getLocalBounds().width;

	switch (this->alignment)
	{
		case WrappableText::TextAlign::CENTER:
			line = string((int) ((remainingWidth / 2) / charWidth), ' ') + line;
			break;
		case WrappableText::TextAlign::RIGHT:
			line = string((int) (remainingWidth / charWidth), ' ') + line;
			break;
	}
}


void WrappableText::initDrawables()
{
	string
		finalText = "",
		line = "";
	float
		charWidth = 10;

	this->uiText = new Text();
	this->uiText->setPosition((float)this->x + this->padding.x, (float)this->y + this->padding.y);
	this->uiText->setFillColor(this->fontColor);
	this->uiText->setString(this->text);
	this->setStyle(this->style);

	charWidth = uiText->getLocalBounds().width / this->text.size();

	for (unsigned int i = 0; i < this->text.size(); i++)
	{
		if ((int)(((line.size() + 1) * charWidth) + this->padding.x) <= this->width - this->padding.x)
		{
			line += this->text[i];
		}
		else
		{
			i--;
			this->addLeftSpaces(line);
			finalText += line + '\n';
			line = "";
		}
	}

	if (line.size() > 0)
	{
		this->addLeftSpaces(line);
		finalText += line;
	}

	this->uiText->setString(finalText);

	if (this->isUnderlined)
	{
		this->drawables["bg"] = new RoundedRectangle(this->parent, this->x, this->y + this->height, 5, this->width, 5, this->bgColor);
	}
	else
	{
		this->drawables["bg"] = new RoundedRectangle(this->parent, this->x, this->y, this->height, this->width, BORDER_RADIUS, this->bgColor);
	}
	this->drawables["text"] = this->uiText;
};

void WrappableText::setStyle(Style style)
{
	this->style = style;
	this->uiText->setFont(*WrappableText::fonts[3]);
	int fontSize = 20;

	switch (style)
	{
	case Style::TITLE:
		this->uiText->setFont(*WrappableText::fonts[0]);
		fontSize = 30;
		break;
	case Style::SUBTITLE:
		this->uiText->setFont(*WrappableText::fonts[1]);
		fontSize = 25;
		break;
	case Style::SCORE:
		this->uiText->setFont(*WrappableText::fonts[0]);
		fontSize = 80;
		break;
	case Style::BODY:
		this->uiText->setFont(*WrappableText::fonts[2]);
		fontSize = 20;
		break;
	}

	this->uiText->setCharacterSize(fontSize);
};