/************************************************//**
 * \file    Console.cpp
 * \brief   Here are defined all methods from Console class
***************************************************/

/**************************************************/
// Libraries

#include "Console.h"


/**************************************************/
// Protected

/*****************************/
// Medoths

void Console::setStyle(Style Style)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (int)Style);
}

/**************************************************/
// Public

/*****************************/
// Medoths

void Console::debug(string title, string message, int line, string file, Message_Type type)
{
	setlocale(LC_ALL, "es_ES");

	cout << endl << endl;
	setStyle(getColorByType(type, Message_Part::TITLE));
	cout << title << endl;
	setStyle(getColorByType(type, Message_Part::MESSAGE));
	cout << '\t' << message << endl;
	setStyle(Style::RESET);
	cout << '\t' << "On line ";
	setStyle(getColorByType(type, Message_Part::LINE));
	cout << line << endl;
	setStyle(Style::RESET);
	cout << '\t' << "In file ";
	setStyle(getColorByType(type, Message_Part::FILE));
	cout << file << endl;
	setStyle(Style::RESET);
};

Console::Style Console::getColorByType(Message_Type type, Message_Part part)
{
	Style Style = Style::RESET;

	switch (type)
	{
		case Message_Type::DEFAULT:
			if (part == Message_Part::TITLE) Style = Style::CYAN;
			else Style = Style::WHITE;
			break;
		case Message_Type::WARNING:
			if (part == Message_Part::TITLE) Style = Style::WARNING;
			else if (part == Message_Part::MESSAGE) Style = Style::YELLOW;
			else Style = Style::WHITE;
			break;
		case Message_Type::ERR:
			if (part == Message_Part::TITLE) Style = Style::ERR;
			else if (part == Message_Part::MESSAGE) Style = Style::RED;
			else Style = Style::WHITE;
			break;
		case Message_Type::FRIENDLY:
			if (part == Message_Part::TITLE) Style = Style::FRIENDLY;
			else if (part == Message_Part::MESSAGE) Style = Style::CYAN;
			else Style = Style::WHITE;
			break;
	}

	return Style;
};
