#include "gles.h"

static uint32_t genIndex = 1;

void anGenBuffers(uint32_t count, uint32_t *buffer) {
    for (int i = 0; i < count; ++i) {
        buffer[i] = ++genIndex;
    }
}

void checkGlError() {
	GLenum err;
	while((err = glGetError()) != GL_NO_ERROR)
	{
		printf("GLError: %s\n", err);
	}
}
