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
// Protected

/*****************************/
// Medoths

/**************************************************/
// Public

/*****************************/
// Constructor

WrappableText::WrappableText(int x, int y, int height, int width, string text, float padding, Style style, Color fontColor, Color bgColor, float borderRadius) : UIElement(x, y, height, width)
{
	this->text = text;
	this->padding = padding;
	this->style = style;
	this->fontColor = fontColor;
	this->bgColor = bgColor;
	this->borderRadius = borderRadius;

	if (!WrappableText::initialized)
	{
		WrappableText::initialized = true;

		for (string fontWeight : this->FontWeight)
		{
			Font* tempFont = new Font();
			if (!tempFont->loadFromFile("resources\\fonts\\MPLUSRounded1c-" + fontWeight + ".ttf"))
			{
				#ifdef _DEBUG
					Console().debug("Error loading font", "There was an error loading MPLUSRounded1c" + fontWeight + ".ttf", __LINE__, __FILE__, Console::MESSAGE_TYPE::ERR);
				#endif
			}

			WrappableText::fonts.push_back(tempFont);
		}
	}

	this->setStyle(this->style);
};


/*****************************/
// Getters and setters methods

/*****************************/
// Medoths

void WrappableText::draw(RenderTexture& canvas)
{
	string
		finalText = "",
		line = "";

	this->uiText.setPosition((float)this->x + this->padding, (float)this->y + this->padding);
	this->uiText.setFillColor(this->fontColor);

	for (unsigned int i = 0; i < this->text.size(); i++)
	{
		if ((int)(((line.size() + 1) * uiText.getCharacterSize()) + this->padding) <= this->width - this->padding)
			line += this->text[i];
		else
		{
			i--;
			finalText += line + '\n';
			line = "";
		}
	}

	this->uiText.setString(finalText);

	RoundedRectangle(this->x, this->y, this->height, this->width, BORDER_RADIUS, this->bgColor).draw(canvas);
	canvas.draw(this->uiText);
};

void WrappableText::setStyle(Style style)
{
	this->uiText.setFont(*WrappableText::fonts[3]);
	int fontSize = 20;

	switch (style)
	{
	case Style::TITLE:
		this->uiText.setFont(*WrappableText::fonts[0]);
		fontSize = 30;
		break;
	case Style::SUBTITLE:
		this->uiText.setFont(*WrappableText::fonts[1]);
		fontSize = 25;
		break;
	case Style::SCORE:
		this->uiText.setFont(*WrappableText::fonts[0]);
		fontSize = 80;
		break;
	case Style::BODY:
		this->uiText.setFont(*WrappableText::fonts[2]);
		fontSize = 20;
		break;
	}

	this->uiText.setCharacterSize(fontSize);
};