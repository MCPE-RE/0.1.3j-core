#include "NinecraftApp.h"
#include "client/renderer/Tesselator.h"
#include "client/input/Multitouch.h"
#include "client/input/mouse/Mouse.h"
#include "math/Mth.h"
#include "material/Material.h"
#include "client/gui/ScreenChooser.h"

bool NinecraftApp::_hasInitedStatics = false;

NinecraftApp::NinecraftApp() {
	this->framesPerSecond = 0;
}

void NinecraftApp::initGLStates() {
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glDepthRangef(0, 1.0f);
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
	Minecraft::onGraphicsReset();
}

bool NinecraftApp::handleBack(bool param) {
	return false;
}

void NinecraftApp::init() {
    Mth::initMth();
    if (!NinecraftApp::_hasInitedStatics) {
        NinecraftApp::_hasInitedStatics = true;
        Material::initMaterials();
    }
	initGLStates();
	Tesselator::instance.init();
	Minecraft::init();
    this->screenChooser.setScreen(START_MENU);
}

void NinecraftApp::update() {
    Multitouch::commit();
    Minecraft::update();
    Mouse::reset2();
}
