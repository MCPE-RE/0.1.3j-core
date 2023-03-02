#include "LevelRenderer.h"

LevelRenderer::LevelRenderer(Minecraft *mc, Textures *textures) {
	this->unknown0 = -9999.0f;
	this->unknown1 = -9999.0f;
	this->unknown2 = -9999.0f;
	this->unknown4 = 2;
	this->minecraft = mc;
	this->unknown9 = -1;
	this->textures = textures;
	this->buffersCount = 34848;
	this->bufferContent = new uint32_t[4 * this->buffersCount];
	anGenBuffers(this->buffersCount, this->bufferContent);
	printf("numBuffers: %d\n", this->buffersCount);
	anGenBuffers(1, this->unknown10);
	this->generateSky();
}

void LevelRenderer::generateSky() {
	Tesselator::instance.begin();
	this->skyVboId = 0;
	for (int i = 4 * -128; 4 * 128 >= i; i += 128) {
		for (int j = 4 * -128; 4 * 128 >= j; j+= 128) {
			Tesselator::instance.vertex((float)i + 0.0f, 16.0f, (float)j + 0.0f);
			Tesselator::instance.vertex((float)(i + 128), 16.0f, (float)j + 0.0f);
			Tesselator::instance.vertex((float)(i + 128), 16.0f, (float)(j + 128));
			Tesselator::instance.vertex((float)i + 0.0f, 16.0f, (float)(j + 128));
			this->skyVboId += 4;
		}
	}
	Tesselator::instance.end(true, this->skyVboId);
}

uint32_t LevelRenderer::getLinearCoord(uint32_t unknown0, uint32_t unknown1, uint32_t unknown2) {
	return unknown0 + this->unknown11 * (unknown1 + unknown2 * this->unknown12);
}

void LevelRenderer::tick() {
	++this->tickCount;
}

void LevelRenderer::setLevel(Level *level) {
    if (this->level != NULL) {
        this->level->removeListener(this);
    }
	this->unknown0 = -9999.0f;
	this->unknown1 = -9999.0f;
	this->unknown2 = -9999.0f;
	// TODO: Entity related stuff
	if (level != NULL) {
		level->addListener(this);
		this->allChanged();
	}
}
