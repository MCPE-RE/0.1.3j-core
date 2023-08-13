#pragma once

#include <cstdint>
#include <cstdio>
#include <map>
#ifdef USE_DESKTOP_GL
#include <glad/gl.h>
#else
#include <GLES/gl.h>
#endif
#include "RenderChunk.h"

class Tesselator {
public:
	static Tesselator instance;
	uint32_t *rawBuffer; //*((_DWORD *)this)
	uint32_t addedVertices; //*((_DWORD *)this + 1)
	float offsetX; //*((_DWORD *)this + 2)
	float offsetY; //*((_DWORD *)this + 3)
	float offsetZ; //*((_DWORD *)this + 4)
	float textureU; //*((_DWORD *)this + 5)
	float textureV; //*((_DWORD *)this + 6)
	uint32_t colorHash; //*((_DWORD *)this + 7)
	uint32_t unknown7; //*((_DWORD *)this + 8)
	uint8_t hasColor; //*((_BYTE *)this + 36)
	uint8_t hasTexture; //*((_BYTE *)this + 37)
	uint8_t unknown10; //*((_BYTE *)this + 38)
	uint8_t noColorEnabled; //*((_BYTE *)this + 39)
	uint8_t voidBeginAndEndCallsEnabled; //*((_BYTE *)this + 40)
	uint32_t vectorIndex; //*((_DWORD *)this + 11)
	uint32_t unknown14; //*((_DWORD *)this + 12)
	uint8_t isDrawing; //*((_BYTE *)this + 52)
	uint32_t vboCount; //*((_DWORD *)this + 14)
	uint32_t vboBufferIndex; //*((_DWORD *)this + 15)
	uint32_t *vboBuffer; //*((_DWORD *)this + 16)
	uint32_t rawBufferSize; //*((_DWORD *)this + 17)
	uint32_t vectorBytesWritten; //*((_DWORD *)this + 18)
	uint32_t vectorCount; //*((_DWORD *)this + 19)
	uint32_t drawMode; //*((_DWORD *)this + 20)
	uint32_t accessMode; //*((_DWORD *)this + 21)
	std::map<uint32_t, int32_t> unknown23; //*((_DWORD *)this + 22)

	Tesselator(uint32_t bufferSize);
	
	void init();
	
	void clear();
	
	uint32_t getVboCount();
	
	RenderChunk end(bool useVboId, uint32_t vboId);
	
	void begin(uint32_t mode);
	
	void begin();

	void tex(float u, float v);
	
	void color(float r, float g, float b);
	
	void color(float r, float g, float b, float a);
	
	void color(int32_t r, int32_t g, int32_t b);
	
	void color(int32_t r, int32_t g, int32_t b, int32_t a);
	
	void color(uint8_t r, uint8_t g, uint8_t b);
	
	void color(int32_t rgb);
	
	void color(int32_t rgb, int32_t a);
	
	void vertexUV(float x, float y, float z, float u, float v);
	
	void vertex(float x, float y, float z);
	
	void noColor();

	void setAccessMode(uint32_t mode);
	
	void normal(float x, float y, float z);
	
	void offset(float x, float y, float z);
	
	void addOffset(float x, float y, float z);
	
	void draw();
	
	void voidBeginAndEndCalls(bool enabled);
};
