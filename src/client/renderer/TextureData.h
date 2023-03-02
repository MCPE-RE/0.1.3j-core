#ifndef TEXTUREDATA_H_
#define TEXTUREDATA_H_

#include <cstddef>
#include <cstdint>

class TextureData {
public:
    int32_t width;
    int32_t height;
    uint8_t *pixels;
    int32_t unknown0;
    bool alpha;
    bool keepBufferData;
    int32_t type;
    int32_t unknown2;

    TextureData();
};

#endif
