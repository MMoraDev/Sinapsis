/************************************************//**
 * \file    Settings.h
 * \brief	This file contains the data about the app
***************************************************/

#pragma once

/**************************************************/
// Libraries
#include <iostream>
#include <SFML/Graphics.hpp>

#include "WrappableText.h"

/**************************************************/
// Namespaces
using namespace std;
using namespace sf;

/**************************************************/
// Constants

const string	APP_TITLE = "100 Mexicanos dijeron";
const Vector2f	PADDING = { 20.f, 10.f };
const float		BORDER_RADIUS = 12;
const string	DATA_PATH = "resources\\data\\";
const string	AVATARS_PATH = "resources\\images\\avatars\\";

/**************************************************/
// Classes

class APP_COLORS {
	public:
		const Color
			PRIMARY = Color(67, 97, 238),
			SECONDARY = Color(76, 201, 240),
			SECONDARY_DARK = Color(72, 149, 239),
			ACCENT = Color(247, 37, 133),
			GRAY = Color(229, 229, 229),
			GRAY_LIGHT = Color(242, 242, 242),
			RED = Color(242, 32, 32),
			RED_DARK = Color(198, 18, 18),
			WHITE = Color(255, 255, 255),
			BLACK = Color(25, 25, 25);
};
