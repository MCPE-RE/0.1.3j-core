#include "ScreenChooser.h"
#include "screens/StartMenuScreen.h"
#include "../../Minecraft.h"

ScreenChooser::ScreenChooser(Minecraft *mc) {
	this->minecraft = mc;
}

void ScreenChooser::setScreen(ScreenId id) {
	if (this->minecraft->isTouchScreen()) {
        switch (id) {
            case START_MENU:
                break;
            case JOIN_GAME:
                break;
            case PAUSE_0:
                break;
            case PAUSE_1:
                break;
            case SELECT_WORLD:
                break;
            case INGAME_BLOCK_SELECTION:
                break;
            default:
               this->minecraft->setScreen(nullptr);
        }
	} else {
        switch (id) {
            case START_MENU:
                this->minecraft->setScreen(new StartMenuScreen());
                break;
            case JOIN_GAME:
                break;
            case PAUSE_0:
                break;
            case PAUSE_1:
                break;
            case SELECT_WORLD:
                break;
            case INGAME_BLOCK_SELECTION:
                break;
            default:
               this->minecraft->setScreen(nullptr);
        }
	}
}

