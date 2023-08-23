#pragma once

#include <string>
#include <algorithm>
#ifdef USE_DESKTOP_GL
#include <glad/gl.h>
#else
#include <GLES/gl.h>
#endif
#include "../../Screen.h"
#include "../../../renderer/TextureData.h"
#include "../../TButton.h"
#include "../../BuyButton.h"
#include "../../LargeImageButton.h"

namespace Touch {
    class StartMenuScreen : public Screen {
    public:
        using Screen::init;
// LargeImageButton SIZE 120
// ImageButton SIZE 116
// BuyButton SIZE 116
// Button SIZE 56
    	LargeImageButton startGameButton; // 60
    	LargeImageButton joinGameButton; // 180
    	LargeImageButton optionsButton; // 300
    	TButton createButton; // 420
    	BuyButton buyButton; // 476
    	std::string copyright; // 592
        uint32_t copyrightX; // 616
    	std::string gameVersion; // 620
        uint32_t gameVersionX; // 644

        StartMenuScreen();

    	void init();

    	void render(uint32_t x, uint32_t y, float unknown2);

        void buttonClicked(Button *button);

        void setupPositions();

        bool isInGameScreen();

        void _updateLicense();

        void tick();
    };
}
