#ifndef APPCONTEXT_H
#define APPCONTEXT_H

#include "AppPlatform.h"

struct AppContext {
	void *eglDisplay; // 0x2c001c
	void *eglContext; // 0x2c0020
	void *eglSurface; // 0x2c0024
    AppPlatform *platform; // 0x2c0028
	bool doRender; // 0x2c002c
};

#endif /* APPCONTEXT_H */
