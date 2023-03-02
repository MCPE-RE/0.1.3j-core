#ifndef FONT_H_
#define FONT_H_

#include <string>
#ifdef USE_DESKTOP_GL
#include <glad/gl.h>
#else
#include <GLES/gl.h>
#endif
#include "../../Options.h"
#include "../renderer/Textures.h"
#include "../renderer/TextureData.h"
#include "../renderer/Tesselator.h"

class Font {
public:
    uint32_t unknown0; // *((uint32_t *)this)
    int32_t charWidthsInt[256]; // *((uint32_t *)this + 1)
    float charWidthsFloat[256]; // *((uint32_t *)this + 257)
    uint32_t unknown1; // *((uint32_t *)this + 513)
    uint32_t unknown2; // *((uint32_t *)this + 514)
    uint32_t unknown3; // *((uint32_t *)this + 515)
    uint32_t unknown4[1024]; // *((uint32_t *)this + 516)
    std::string textureName; // *((uint32_t *)this + 1540)
	Textures *textures; // *((uint32_t *)this + 1546)
	Options *options; // *((uint32_t *)this + 1547)

	Font(Options *options, const std::string& textureName, Textures *textures);

	void init(Options *opt);

	void buildChar(uint8_t c, float x, float y);

	void drawSlow(const std::string& text, int32_t x, int32_t y, int32_t colorHash, bool darken);

    void draw(const std::string& text, int32_t x, int32_t y, int32_t colorHash, bool darken);

    void draw(const std::string& text, int32_t x, int32_t y, int32_t colorHash);

    void drawShadow(const std::string& text, int32_t x, int32_t y, int32_t colorHash);

    void onGraphicsReset();

    std::string sanitize(const std::string& text);

    int32_t width(const std::string& text);

    int32_t height(const std::string& text);

    void drawWordWrap(const std::string& text, int32_t x, int32_t y, int32_t maxLineWidth, int32_t colorHash);

	virtual ~Font();
};

#endif /* FONT_H_ */
