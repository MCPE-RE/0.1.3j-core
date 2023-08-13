#pragma once

#include <vector>
#ifdef USE_DESKTOP_GL
#include <glad/gl.h>
#else
#include <GLES/gl.h>
#endif
#include "GuiComponent.h"
#include "../renderer/Tesselator.h"
#include "Font.h"
#include "Button.h"

class Minecraft;

class Screen : public GuiComponent {
public:
	uint32_t width; // *((uint32_t *)this + 2)
	uint32_t height; // *((uint32_t *)this + 3)
	uint8_t disallowEvents; // *((uint8_t *)this + 16)
	Minecraft *minecraft; // *((uint32_t *)this + 5)
	std::vector<Button*> buttonList; // *((uint32_t *)this + 6)
	std::vector<Button*> tabButtonList; // *((uint32_t *)this + 9)
	uint32_t buttonIndex; // *((uint32_t *)this + 12)
	Font *font; // *((uint32_t *)this + 13)
	Button *pressedButton; // *((uint32_t *)this + 14)

	Screen();

	virtual void render(uint32_t x, uint32_t y, float unknown2);

	virtual void init();

	virtual void setupPositions();

	void updateEvents();

	void mouseEvent();

	void keyboardEvent();

	void keyPressed(uint32_t key);

	bool handleBackEvent(bool keepScreen);

	virtual void tick();

	void removed();

	bool isPauseScreen();

	bool isErrorScreen();

	virtual bool isInGameScreen();

	bool clearColorBuffer();

	void confirmResult(bool unknown0, uint32_t unknown1);

	void init(Minecraft *mc, uint32_t width, uint32_t height);

	virtual void buttonClicked(Button *button);

	void mouseClicked(uint32_t x, uint32_t y, uint32_t button);

	void mouseReleased(uint32_t x, uint32_t y, uint32_t button);

	void renderBackground();

	void renderBackground(uint32_t textureVOffset);

	void updateTabButtonSelection();

	void renderDirtBackground(int unknown);

	void setSize(uint32_t width, uint32_t height);
};
