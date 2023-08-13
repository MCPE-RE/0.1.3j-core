#pragma once

#include <string>
#include "client/renderer/TextureData.h"
#include <vector>

#ifdef USE_DESKTOP_GL
#include <glad/gl.h>
#else
#include <GLES/gl.h>
#endif

class AppPlatform {
public:
	AppPlatform();

	virtual void _tick();

	virtual void buyGame();

	virtual int checkLicense();

	virtual void createUserInput();

    virtual void createUserInput(int dialogueId);

	virtual void finish();

	virtual std::string getDateString(int seconds);

	virtual std::vector<std::string> getOptionStrings();

	virtual float getPixelsPerMillimeter();

	virtual int getScreenHeight();

	virtual int getScreenWidth();

	virtual std::vector<std::string> getUserInput();

	virtual int getUserInputStatus();

	virtual bool hasBuyButtonWhenInvalidLicense();

	virtual bool isPowerVR();

	virtual bool isTouchscreen();

	virtual TextureData loadTexture(const std::string &name, bool alpha);

	virtual void playSound(const std::string &name, float volume, float pitch);

	virtual void saveScreenshot(const std::string &path, int width, int height);

	virtual void showDialog(int dialogueId);

	virtual void uploadPlatformDependentData(int unknown0, void *unknown1);
    
	virtual void vibrate(int milliseconds);
};
