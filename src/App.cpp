#include <cstdlib>
#include "App.h"
#include "AppContext.h"

#ifdef USE_DESKTOP_GL
#include <glad/egl.h>
#else
#include <EGL/egl.h>
#endif

App::App() {
	this->inited = false;
	this->quitIntention = false;
	this->appPlatform = NULL;
}

AppPlatform *App::platform() {
	return this->appPlatform;
}

void App::init() {}

void App::init(AppContext *appCtx) {
	this->display = appCtx->eglDisplay;
	this->context = appCtx->eglContext;
	this->surface = appCtx->eglSurface;
	this->appPlatform = appCtx->platform;
	this->doRender = appCtx->doRender;
	this->init();
	this->inited = true;
}

void App::onGraphicsReset(AppContext *appCtx) {
	this->display = appCtx->eglDisplay;
	this->context = appCtx->eglContext;
	this->surface = appCtx->eglSurface;
	this->appPlatform = appCtx->platform;
	this->doRender = appCtx->doRender;
	this->onGraphicsReset();
}

void App::swapBuffers() {
	if (this->doRender) {
        eglSwapBuffers(this->display, this->surface);
    }
}

bool App::handleBack(bool param) {
    return false;
}

void App::draw() {}

void App::saveState(void **state, size_t *size) {

}

void App::update() {}

void App::audioEngineOn() {}

void App::audioEngineOff() {}

void App::setSize(int width, int height) {}

bool App::isInited() {
	return this->inited;
}

bool App::wantToQuit() {
	return this->quitIntention;
}

void App::quit() {
	this->quitIntention = true;
}

void App::destroy() {}