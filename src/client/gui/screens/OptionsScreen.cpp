#include "OptionsScreen.h"
#include "../../../AppPlatform.h"
#include "../ScreenChooser.h"
#include "../../../Minecraft.h"

void OptionsScreen::init() {
	this->dialogCreationStep = 2;
}

void OptionsScreen::removed() {}

void OptionsScreen::render(uint32_t x, uint32_t y, float unknown2) {
	this->renderBackground();
    --this->dialogCreationStep;
    AppPlatform *platform = this->minecraft->platform();
    if (this->dialogCreationStep == 0) {
        platform->createUserInput(3);
    } else if (this->dialogCreationStep < 0) {
        if (platform->getUserInputStatus() >= 0) {
            this->minecraft->reloadOptions();
            this->minecraft->screenChooser.setScreen(START_MENU);
        }
    }
}