/************************************************//**
 * \file    SlideableMenu.h
***************************************************/

#pragma once

/**************************************************/
// Libraries

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "TextField.h"
#include "UIElement.h"

/**************************************************/
// Namespaces

using namespace std;
using namespace sf;

/**************************************************/
/**
 * SlideableMenu class
 */
class SlideableMenu : public UIElement
{
    private:
        /********************/
        // Methods
        void loop() override;

    public:
        /********************/
        // Structs

        struct AnimationData {
            const enum class Direction {
                LEFT,
                RIGHT,
            };

            float gap = 0;
            bool isChangingOption = false;
            Direction direction = Direction::LEFT;
        };

    protected:
        /********************/
        // Variables

        float MAX_GAP = 50;

        /********************/
        // Variables

        map<string, vector<string>> options;
        map<string, vector<string>>::iterator actualSection;
        int actualOption;
        vector<Image> arrowImages;
        AnimationData animation;
        Texture *icon;
        map<string, string> selectedOption;
        string path;
        bool 
            isEditable,
            isReadOnly;

        /********************/
        // Methods

    public:
        /********************/
        // Constructor

        /**
         * SlideableMenu Constructor.
         *
         * \param parent The pointer of the window that contains the element.
         * \param x The x coordinate.
         * \param y The y coordinate.
         * \param height The desired height for the element.
         * \param width The desired width for the element.
         * \param options The desired options.
         * \param path The path of the folder that contains the images.
         * \param isEditable (Optional) Instead of setting a WrappableText, it will use a TextField.
         * \param isReadOnly (Optional)
         */
        SlideableMenu(RenderWindow* parent, int x, int y, int height, int width, map<string, vector<string>> options, string path, bool isEditable = false, bool isReadOnly = false);

        /********************/
        // Getters and setters methods

        map<string, string> getData();

        map<string, string> getSelectedOption();
        void setSelectedOption(map<string, string> option);


        TextField * getTextFieldPtr();

        /********************/
        // Methods

        void changeOption();

        /**
         * \brief Prints the ui on the canvas (doesn't show it on screen).
         */
        void initDrawables();

        void loadOption();
};
