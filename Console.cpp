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

void Console::setStyle(STYLE style)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (int)style);
}

/**************************************************/
// Public

/*****************************/
// Medoths

void Console::debug(string title, string message, int line, string file, MESSAGE_TYPE type)
{
	setlocale(LC_ALL, "es_ES");

	cout << endl << endl;
	setStyle(getColorByType(type, MESSAGE_PART::TITLE));
	cout << title << endl;
	setStyle(getColorByType(type, MESSAGE_PART::MESSAGE));
	cout << '\t' << message << endl;
	setStyle(STYLE::RESET);
	cout << '\t' << "On line ";
	setStyle(getColorByType(type, MESSAGE_PART::LINE));
	cout << line << endl;
	setStyle(STYLE::RESET);
	cout << '\t' << "In file ";
	setStyle(getColorByType(type, MESSAGE_PART::FILE));
	cout << file << endl;
	setStyle(STYLE::RESET);
};

Console::STYLE Console::getColorByType(MESSAGE_TYPE type, MESSAGE_PART part)
{
	STYLE style = STYLE::RESET;

	switch (type)
	{
		case MESSAGE_TYPE::DEFAULT:
			if (part == MESSAGE_PART::TITLE) style = STYLE::CYAN;
			else style = STYLE::WHITE;
			break;
		case MESSAGE_TYPE::WARNING:
			if (part == MESSAGE_PART::TITLE) style = STYLE::WARNING;
			else if (part == MESSAGE_PART::MESSAGE) style = STYLE::YELLOW;
			else style = STYLE::WHITE;
			break;
		case MESSAGE_TYPE::ERR:
			if (part == MESSAGE_PART::TITLE) style = STYLE::ERR;
			else if (part == MESSAGE_PART::MESSAGE) style = STYLE::RED;
			else style = STYLE::WHITE;
			break;
		case MESSAGE_TYPE::FRIENDLY:
			if (part == MESSAGE_PART::TITLE) style = STYLE::FRIENDLY;
			else if (part == MESSAGE_PART::MESSAGE) style = STYLE::CYAN;
			else style = STYLE::WHITE;
			break;
	}

	return style;
};
