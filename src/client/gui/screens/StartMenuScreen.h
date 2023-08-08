#ifndef STARTMENUSCREEN_H_
#define STARTMENUSCREEN_H_

#include <string>
#include <algorithm>
#ifdef USE_DESKTOP_GL
#include <glad/gl.h>
#else
#include <GLES/gl.h>
#endif
#include "../Screen.h"
#include "../../renderer/TextureData.h"

class StartMenuScreen : public Screen {
public:
    using Screen::init;

	Button startGameButton; // 60
	Button joinGameButton; // 116
	Button optionsButton; // 172
	Button createButton; // 228
	Button buyButton; // 284
	std::string copyright; // 340
    uint32_t copyrightX; // 364
	std::string gameVersion; // 368
    uint32_t gameVersionX; // 392

    StartMenuScreen();

	void init();

	void render(uint32_t x, uint32_t y, float unknown2);

    void buttonClicked(Button *button);

    void setupPositions();

    bool isInGameScreen();

    void _updateLicense();

    void tick();
};

#endif /* STARTMENUSCREEN_H_ */
