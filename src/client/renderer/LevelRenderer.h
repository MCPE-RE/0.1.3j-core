#ifndef LEVELRENDERER_H_
#define LEVELRENDERER_H_

#include <stddef.h>
#include <vector>
#include "../../LevelListener.h"
#include "../../Level.h"
#include "gles.h"
#include "Textures.h"
#include "Tesselator.h"

class Minecraft;

class LevelRenderer : LevelListener {
public:
	float unknown0; // 4
	float unknown1; // 8
	float unknown2; // 12
	uint32_t unknown3; // 16
	uint32_t unknown4; // 20
	uint32_t unknown5; // 24
	uint32_t unknown6; // 28
	uint32_t unknown7; // 32
	// TODO: class Chunk
	std::vector<void *> chunks; // 36
	uint32_t unknown8; // 48
	void *renderList; // 52

	Level *level; // 132

	uint32_t unknown11; // 164
	uint32_t unknown12; // 168

	Minecraft *minecraft; // 180

	uint32_t unknown9; // 188

	uint32_t tickCount; // 192

	uint32_t buffersCount; // 208
	uint32_t *bufferContent; // 212
	uint32_t unknown10; // 216

	uint32_t skyVboId; // 220

	Textures *textures; // 224;

    uint32_t getLinearCoord(uint32_t unknown0, uint32_t unknown1, uint32_t unknown2);

    LevelRenderer(Minecraft *mc, Textures *textures);
    
    void generateSky();

	void onGraphicsReset();

	void allChanged();

    void tick();

    void setLevel(Level *level);
};

#endif
