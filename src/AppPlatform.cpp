#include "AppPlatform.h"
#include <cstring>

AppPlatform::AppPlatform() {
	// TODO Auto-generated constructor stub
}

void AppPlatform::_tick() {}

void AppPlatform::buyGame() {}

int AppPlatform::checkLicense() {
	return 0;
}

void AppPlatform::createUserInput() {}

void AppPlatform::createUserInput(int dialogueId) {
    this->showDialog(dialogueId);
    this->createUserInput();
}

void AppPlatform::finish() {}

std::string AppPlatform::getDateString(int seconds) {
	return "";
}

std::vector<std::string> AppPlatform::getOptionStrings() {
    std::vector<std::string> vec;
	return vec;
}

float AppPlatform::getPixelsPerMillimeter() {
	return 10.0;
}

int AppPlatform::getScreenHeight() {
	return 480;
}

int AppPlatform::getScreenWidth() {
	return 854;
}

std::vector<std::string> AppPlatform::getUserInput() {
	std::vector<std::string> vec;
	return vec;
}

int AppPlatform::getUserInputStatus() {
	return 0;
}

bool AppPlatform::hasBuyButtonWhenInvalidLicense() {
	return false;
}

bool AppPlatform::isPowerVR() {
	const GLubyte *haystack = glGetString(GL_RENDERER);
	if (haystack == NULL) {
		return false;
	}
	return strstr((const char *)haystack, "SGX") != NULL;
}

bool AppPlatform::isTouchscreen() {
	return true;
}

TextureData AppPlatform::loadTexture(const std::string &name, bool alpha) {
    return TextureData();
}

void AppPlatform::playSound(const std::string &name, float volume, float pitch) {}

void AppPlatform::saveScreenshot(const std::string &path, int width, int height) {}

void AppPlatform::showDialog(int dialogueId) {}

void AppPlatform::uploadPlatformDependentData(int unknown0, void *unknown1) {}

void AppPlatform::vibrate(int milliseconds) {}

AppPlatform::~AppPlatform() {
	// TODO Auto-generated destructor stub
}

