/************************************************//**
 * \file    MainView.cpp
 * \brief   Here are defined all methods from MainView class
***************************************************/

/**************************************************/
// Libraries

#include <iostream>
#include <SFML/Graphics.hpp>

#include "MainView.h"
#include "UIElement.h"

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
// Public

/*****************************/
// Constructor

MainView::MainView(RenderWindow* parent, int x, int y, int height, int width) : UIElement(parent, x, y, height, width)
{
	this->playAudio = map<string, bool>();
};

/*****************************/
// Getters and setters methods

map<string, bool> MainView::getPlayAudio() { return this->playAudio; };
void MainView::setPlayAudio(map<string, bool>) { this->playAudio = playAudio; };

/*****************************/
// Medoths
