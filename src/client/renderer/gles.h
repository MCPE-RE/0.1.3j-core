#ifndef GLES_H_
#define GLES_H_

#include <cstdint>
#ifdef USE_DESKTOP_GL
#include <glad/gl.h>
#else
#include <GLES/gl.h>
#endif
#include <stdio.h>

void anGenBuffers(uint32_t count, uint32_t *buffer);

void checkGlError();  // Maybe has a string parameter like the java alpha

#endif
