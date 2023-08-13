#pragma once

#include <string>
#ifdef USE_DESKTOP_GL
#include <glad/gl.h>
#else
#include <GLES/gl.h>
#endif

#include "Minecraft.h"
#include "AppContext.h"
#include "App.h"

class NinecraftApp : public Minecraft {
public:
    static bool _hasInitedStatics;
    
    using Minecraft::init;

	std::string absolutePathDirectory;
	// EGLDisplay display;
	// EGLContext context;
	// EGLSurface surface;
	int framesPerSecond;

	NinecraftApp();

	void initGLStates();

	bool handleBack(bool);

	void init();

    void update();

	void onGraphicsReset();
};
