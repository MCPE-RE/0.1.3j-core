#include "Tesselator.h"
#include "gles.h"
#include <cstdint>
#include <iostream>

Tesselator Tesselator::instance = Tesselator(0x800000);

Tesselator::Tesselator(uint32_t bufferSize) {
	this->addedVertices = 0;
	this->offsetX = 0.0f;
	this->offsetY = 0.0f;
	this->offsetZ = 0.0f;
	this->textureU = 0.0f;
	this->textureV = 0.0f;
	this->colorHash = 0;
	this->unknown7 = 0;
	this->hasColor = false;
	this->hasTexture = false;
	this->unknown10 = 0;
	this->noColorEnabled = false;
	this->voidBeginAndEndCallsEnabled = false;
	this->vectorIndex = 0;
	this->unknown14 = 0;
	this->isDrawing = false;
	this->vboCount = 1024;
	this->vboBufferIndex = -1;
	this->rawBufferSize = bufferSize;
	this->vectorBytesWritten = 0;  // Bytes written to a vertex buffer object (VBO) (?)
	this->vectorCount = bufferSize / 24;
	this->drawMode = 0;
	this->accessMode = 2;
    this->vboBuffer = new uint32_t[this->vboCount];
    this->rawBuffer = new uint32_t[6 * this->vectorCount];
	printf("Vsize: %lu, %d\n", 24, 24);
}

void Tesselator::init() {
    anGenBuffers(this->vboCount, this->vboBuffer);
}

void Tesselator::clear() {
	this->accessMode = 2;  // TODO: enum
	this->addedVertices = 0;
	this->unknown14 = 0;
	this->vectorIndex = 0;
	this->voidBeginAndEndCallsEnabled = false;
}

uint32_t Tesselator::getVboCount() {
	return this->vboCount;
}


RenderChunk Tesselator::end(bool useVboId, uint32_t vboId) {
	uint32_t targetVboId = vboId;
    if (!this->isDrawing || this->voidBeginAndEndCallsEnabled) {
        return RenderChunk();
    }
    this->isDrawing = false;
    if (this->addedVertices > 0) {
        if (++this->vboBufferIndex >= this->vboCount) {
            this->vboBufferIndex = 0;
        }
        if (!useVboId) {
			targetVboId = this->vboBuffer[this->vboBufferIndex];
        }
        GLenum mode = GL_STATIC_DRAW;
		if (this->accessMode == 1) {
			mode = GL_DYNAMIC_DRAW;
		}
		uint32_t targetVectorIndex = this->vectorIndex * 24;
		glBindBuffer(GL_ARRAY_BUFFER, targetVboId);
		glBufferData(GL_ARRAY_BUFFER, targetVectorIndex, this->rawBuffer, mode);
		this->vectorBytesWritten += targetVectorIndex;
	}
	this->clear();
	return RenderChunk(targetVboId, this->addedVertices);
}

void Tesselator::begin(uint32_t mode) {
	if (!this->isDrawing && !this->voidBeginAndEndCallsEnabled) {
		this->isDrawing = true;
		this->clear();
		this->drawMode = mode;
		this->unknown10 = 0;
		this->hasColor = false;
		this->hasTexture = false;
		this->noColorEnabled = false;
	}
}
	
void Tesselator::begin() {
	this->begin(7);
}

void Tesselator::tex(float u, float v) {
	this->hasTexture = true;
	this->textureU = u;
	this->textureV = v;
}

void Tesselator::color(float r, float g, float b) {
	color((int32_t)(r * 255.0f), (int32_t)(g * 255.0f), (int32_t)(b * 255.0f));
}

void Tesselator::color(float r, float g, float b, float a) {
	color((int32_t)(r * 255.0f), (int32_t)(g * 255.0f), (int32_t)(b * 255.0f), (int32_t)(a * 255.0f));
}

void Tesselator::color(int32_t r, int32_t g, int32_t b) {
	color(r, g, b, 255);
}

void Tesselator::color(int32_t r, int32_t g, int32_t b, int32_t a) {
	if (!this->noColorEnabled) {
		// prob a one liner
		r = std::max(std::min(r, 255), 0);
		g = std::max(std::min(r, 255), 0);
		b = std::max(std::min(r, 255), 0);
		a = std::max(std::min(r, 255), 0);

		this->hasColor = true;
		this->colorHash = (a << 24) | (b << 16) | (g << 8) | r;
	}
}

void Tesselator::color(uint8_t r, uint8_t g, uint8_t b) {
	color((int32_t)r, (int32_t)g, (int32_t)b);
}

void Tesselator::color(int32_t rgb) {
	color((rgb & 0xFF0000) >> 16, (rgb & 0xFF00) >> 8, (rgb & 0xFF));
}

void Tesselator::color(int32_t rgb, int32_t a) {
	color((rgb & 0xFF0000) >> 16, (rgb & 0xFF00) >> 8, (rgb & 0xFF), a);
}

void Tesselator::vertexUV(float x, float y, float z, float u, float v) {
	this->tex(u, v);
	this->vertex(x, y, z);
}

void Tesselator::vertex(float x, float y, float z) {
	++this->unknown14;
	if (this->drawMode == 7 && !(this->unknown14 & 3)) {
		for (int i = 0; i < 2; ++i) {
			uint32_t *vetexBufferSrc = &this->rawBuffer[6 * (this->vectorIndex - (3 - i))];
			uint32_t *vetexBufferDst = &this->rawBuffer[6 * this->vectorIndex];
			if (this->hasTexture) {
				vetexBufferDst[3] = vetexBufferSrc[3];
				vetexBufferDst[4] = vetexBufferSrc[4];
			}
			if (this->hasColor) {
				vetexBufferDst[5] = vetexBufferSrc[5];
			}
			vetexBufferDst[0] = vetexBufferSrc[0];
			vetexBufferDst[1] = vetexBufferSrc[1];
			vetexBufferDst[2] = vetexBufferSrc[2];
			++this->addedVertices;
			++this->vectorIndex;
		}
	}
	float *vetexBuffer = (float *)&this->rawBuffer[6 * this->vectorIndex];
	if (this->hasTexture) {
		vetexBuffer[3] = this->textureU;
		vetexBuffer[4] = this->textureV;
	}
	if (this->hasColor) {
		vetexBuffer[5] = *(float *)&this->colorHash;
	}
	vetexBuffer[0] = this->offsetX + x;
	vetexBuffer[1] = this->offsetY + y;
	vetexBuffer[2] = this->offsetZ + z;
	++this->vectorIndex;
	if (!(++this->addedVertices & 3) && this->vectorIndex >= this->vectorCount - 1) {
		for (int j = 0; j < 3; ++j ) {
			puts("Overwriting the vertex buffer! This chunk/entity won't show up");
		}
		this->clear();
	}
}

void Tesselator::noColor() {
    this->noColorEnabled = true;
}

void Tesselator::setAccessMode(uint32_t mode) {
	this->accessMode = mode;
}

void Tesselator::normal(float x, float y, float z) {}

void Tesselator::offset(float x, float y, float z) {
	this->offsetX = x;
	this->offsetY = y;
	this->offsetZ = z;
}

void Tesselator::addOffset(float x, float y, float z) {
	this->offsetX += x;
	this->offsetY += y;
	this->offsetZ += z;
}

void Tesselator::draw() {
	if (this->isDrawing && !this->voidBeginAndEndCallsEnabled) {
		this->isDrawing = false;
		if (this->addedVertices > 0) {
			if (++this->vboBufferIndex >= this->vboCount) {
				this->vboBufferIndex = 0;
			}

			GLenum usage;
			if (this->accessMode == 1) {
				usage = GL_DYNAMIC_DRAW;
			} else {
                usage = GL_STATIC_DRAW;
            }

			glBindBuffer(GL_ARRAY_BUFFER, this->vboBuffer[this->vboBufferIndex]);
			glBufferData(GL_ARRAY_BUFFER, 24 * this->vectorIndex, this->rawBuffer, usage);

			if (this->hasTexture) {
				glTexCoordPointer(2, GL_FLOAT, 24, (const GLvoid *)12);
				glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			}

			if (this->hasColor) {
				glColorPointer(4, GL_UNSIGNED_BYTE, 24, (const GLvoid *)20);
				glEnableClientState(GL_COLOR_ARRAY);
			}

			glVertexPointer(3, GL_FLOAT, 24, 0);
			glEnableClientState(GL_VERTEX_ARRAY);

			if (this->drawMode == 7) {
				glDrawArrays(GL_TRIANGLES, 0, this->addedVertices);
			} else {
				glDrawArrays(this->drawMode, 0, this->addedVertices);
			}

			glDisableClientState(GL_VERTEX_ARRAY);

			if (this->hasTexture) {
				glDisableClientState(GL_TEXTURE_COORD_ARRAY);
			}

			if (this->hasColor) {
				glDisableClientState(GL_COLOR_ARRAY);
			}
		}
		this->clear();
	}
}

void Tesselator::voidBeginAndEndCalls(bool enabled) {
	this->voidBeginAndEndCallsEnabled = enabled;
}
