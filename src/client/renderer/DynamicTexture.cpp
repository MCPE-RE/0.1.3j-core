#include "DynamicTexture.h"
#include <cstring>
#include "Textures.h"

DynamicTexture::DynamicTexture(int32_t tileSideSize)  {
    this->tileSideSize = tileSideSize;
    this->tileCount = 1;
    memset(this->data, 0, 0x400);
}

void DynamicTexture::tick() {}

void DynamicTexture::bindTexture(Textures *textures) {
    textures->loadAndBindTexture("terrain.png");
}