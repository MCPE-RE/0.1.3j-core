#include "Screen.h"
#include "../../Minecraft.h"
#include "../input/keyboard/Keyboard.h"
#include "../input/mouse/Mouse.h"

Screen::Screen() {
	this->width = 1;
	this->height = 1;
	this->disallowEvents = false;
	this->buttonIndex = 0;
	this->pressedButton = nullptr;
}

void Screen::init() {}

void Screen::init(Minecraft *mc, uint32_t width, uint32_t height) {
	this->minecraft = mc;
	this->font = mc->font;
	this->width = width;
	this->height = height;
	this->init();
	this->setupPositions();
	this->updateTabButtonSelection();
}

void Screen::render(uint32_t x, uint32_t y, float unknown2) {
	// TODO: third parameter
	for (size_t i = 0; i < this->buttonList.size(); ++i) {
		this->buttonList[i]->render(this->minecraft, x, y);
	}
}

void Screen::removed() {};

void Screen::setupPositions() {}

void Screen::renderBackground() {
	this->renderBackground(0);
}

void Screen::renderBackground(uint32_t textureVOffset) {
    if (this->minecraft->isLevelGenerated()) {
        this->fillGradient(0, 0, this->width, this->height, 0xC0101010, 0xD0101010);
    } else {
        this->renderDirtBackground(textureVOffset);
    }
	
}

void Screen::renderDirtBackground(int textureVOffset) {
	glDisable(GL_FOG);
	this->minecraft->textures->loadAndBindTexture("gui/background.png");
	glColor4f(1.0, 1.0, 1.0, 1.0);
	Tesselator::instance.begin();
	Tesselator::instance.color(0x404040);
	Tesselator::instance.vertexUV(0.0f, (float)this->height, 0.0f, 0.0f, ((float)this->height / 32.0f) + (float)textureVOffset);
	Tesselator::instance.vertexUV((float)this->width, (float)this->height, 0.0f, (float)this->width / 32.0f, ((float)this->height / 32.0f) + (float)textureVOffset);
	Tesselator::instance.vertexUV((float)this->width, 0.0f, 0.0f, (float)this->width / 32.0f, (float)textureVOffset + 0.0f);
	Tesselator::instance.vertexUV(0.0f, 0.0f, 0.0f, 0.0f, (float)textureVOffset + 0.0f);
	Tesselator::instance.draw();
}

void Screen::updateTabButtonSelection() {
    if (!this->minecraft->isTouchScreen()) {
        for (size_t i = 0; i < this->tabButtonList.size(); ++i) {
            this->tabButtonList[i]->isHovered = this->buttonIndex == i;
		    }
	  }
}

void Screen::confirmResult(bool unknown0, uint32_t unknown1) {}

bool Screen::clearColorBuffer() {
	return true;
}

void Screen::setSize(uint32_t width, uint32_t height) {
	this->width = width;
	this->height = height;
	this->setupPositions();
}

bool Screen::isErrorScreen() {
	return false;
}

bool Screen::isInGameScreen() {
	return true;
}

bool Screen::isPauseScreen() {
	return true;
}

void Screen::tick() {};

void Screen::buttonClicked(Button *button) {}

void Screen::updateEvents() {
    if (!this->disallowEvents) {
        while (Mouse::next()) {
            this->mouseEvent();
        }
        while (Keyboard::next()) {
            this->keyboardEvent();
        }
    }
}

bool Screen::handleBackEvent(bool keepScreen) {
	return false;
}

void Screen::keyPressed(uint32_t key) {
    if (key == 0x1b) {
        this->minecraft->setScreen(NULL);
    }
    if (this->minecraft->isTouchScreen() == false && this->tabButtonList.size() != 0) {
        if (this->minecraft->options.keyMenuNext.keyCode == key) {
            ++this->buttonIndex;
            if (this->buttonIndex == this->tabButtonList.size()) {
                this->buttonIndex = 0;
            }
        }
        if (this->minecraft->options.keyMenuPrevious.keyCode == key) {
            --this->buttonIndex;
            if (this->buttonIndex == this->tabButtonList.size()) {
                this->buttonIndex = 0;
            }
            if (this->buttonIndex == -1) {
              this->buttonIndex = this->tabButtonList.size() - 1;
            }
        }
        if (this->minecraft->options.keyMenuOk.keyCode == key) {
            Button *btn = this->tabButtonList[this->buttonIndex];
            if (btn->isUsable) {
                this->minecraft->soundEngine->playUI("random.click", 1.0, 1.0);
                this->buttonClicked(btn);
            }
        }
        this->updateTabButtonSelection();
    }
}

void Screen::mouseEvent() {
    MouseAction *action = Mouse::getEvent();
    if (action->isButton()) {
        int x = (this->width * action->x) / this->minecraft->width;
        int y = (this->height * action->y) / this->minecraft->height;
        if (Mouse::getEventButtonState()) {
            this->mouseClicked(x, y - 1, Mouse::getEventButton());
        } else {
            this->mouseReleased(x, y - 1, Mouse::getEventButton());
        }
    }
}

void Screen::mouseClicked(uint32_t x, uint32_t y, uint32_t button) {
    if (button == 1) {
        for (size_t i = 0; i < this->buttonList.size(); ++i) {
            Button *btn = this->buttonList[i];
            if (btn->clicked(this->minecraft, x, y)) {
                btn->setPressed();
                this->pressedButton = btn;
            }
        }
    }
}

void Screen::mouseReleased(uint32_t x, uint32_t y, uint32_t button) {
	if (this->pressedButton != nullptr && button == 1) {
        for (size_t i = 0; i < this->buttonList.size(); ++i) {
            Button *btn = this->buttonList[i];
            if (btn == this->pressedButton && btn->clicked(this->minecraft, x, y)) {
                this->buttonClicked(btn);
                this->minecraft->soundEngine->playUI("random.click", 1.0, 1.0);
                this->pressedButton->released(x, y);
            }
        }
        this->pressedButton = nullptr;
    }
}

void Screen::keyboardEvent() {
	if (Keyboard::getEventKeyState() != 0) {
		this->keyPressed(Keyboard::getEventKey());
	}
}