#pragma once

#include "AppContext.h"
#include "AppPlatform.h"

class App {
public:
	void *display;
    void *context;
	void *surface;

	AppPlatform *appPlatform;
    bool doRender;

	bool inited;
	bool quitIntention;

	App();

	AppPlatform *platform();

	virtual bool handleBack(bool param);

	virtual void init();

	void init(AppContext *appCtx);

	void onGraphicsReset(AppContext *appCtx);

	virtual void onGraphicsReset() = 0;  // todo: to confirm as a pure virtual

	void draw();

	void audioEngineOn();

	void audioEngineOff();

	void saveState(void **state, size_t *size);
	
	void update();

	void swapBuffers();

	bool isInited();

	void quit();

	void setSize(int, int);

	bool wantToQuit();
	
	void destroy();
};
