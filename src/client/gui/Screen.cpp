#include "Screen.h"
#include "../../Minecraft.h"

Screen::Screen() {
	this->width = 1;
	this->height = 1;
	this->unknown1 = false;
	this->unknown2 = 0;
	this->unknown3 = 0;
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
	for (int i = 0; i < this->buttonList.size(); ++i) {
		this->buttonList[i]->render(this->minecraft, x, y);
	}
}

void Screen::removed() {};

void Screen::setupPositions() {}

void Screen::renderBackground() {
	this->renderBackground(0);
}

void Screen::renderBackground(uint32_t textureVOffset) {
	// TODO: Minecraft::isLevelGenerated
	this->fillGradient(0, 0, this->width, this->height, 0xC0101010, 0xD0101010);
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
		for (int i = 0; this->tabButtonList.size() > i; ++i) {
			// TODO: figure out the + 54 thing
			// this->tabButtonList[i] = this->unknown2 == i;
		}
	}
}

void Screen::confirmResult(bool unknown0, uint32_t unknown1) {}

bool Screen::clearColorBuffer() {
	return false;
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
	// TODO: Keyboard
}

bool Screen::handleBackEvent(bool unknown0) {
	return false;
}

void Screen::keyPressed(uint32_t key) {
	// TODO
}

void Screen::mouseEvent() {
	// TODO: MouseAction, Mouse
}

void Screen::mouseClicked(uint32_t x, uint32_t y, uint32_t z) {
	// TODO
}

void Screen::mouseReleased(uint32_t x, uint32_t y, uint32_t z) {
	// TODO
}

Screen::~Screen() {
	// TODO Auto-generated destructor stub
}
