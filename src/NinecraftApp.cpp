#include "NinecraftApp.h"
#include "client/renderer/Tesselator.h"

NinecraftApp::NinecraftApp() {
	this->framesPerSecond = 0;
}

void NinecraftApp::initGLStates() {
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
    #ifndef USE_DESKTOP_GL
	glDepthRangef(0, 1.0);
    #else
    glDepthRange(0, 1.0);
    #endif
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_TEXTURE_2D);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);

	// TODO: this is a boolean value
	// and seems like to do the following thing
	this->powerVR = this->platform()->isPowerVR();
}

void NinecraftApp::onGraphicsReset() {
	this->initGLStates();
	Tesselator::instance.init();
	// Minecraft::onGraphicsReset();
}

bool NinecraftApp::handleBack(bool param) {
	return false;
}

void NinecraftApp::init() {
	initGLStates();
	Tesselator::instance.init();
	Minecraft::init();
}

void NinecraftApp::update() {
    Minecraft::update();
}

NinecraftApp::~NinecraftApp() {
	// TODO Auto-generated destructor stub
}

