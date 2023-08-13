#pragma once

#include <cstdint>
#include "Font.h"

class GuiComponent {
public:
	float zCoord;

	GuiComponent();

	void fill(int32_t leftEdge, int32_t topEdge, int32_t rightEdge, int32_t bottomEdge, int32_t colorHash);

	void fillGradient(int32_t xLeft, int32_t yTop, int32_t xRight, int32_t yBottom, int32_t colorTop, int32_t colorBottom);

	void blit(int32_t x, int32_t y, int32_t srcX, int32_t srcY, int32_t srcWidth, int32_t srcHeight, int32_t destWidth, int32_t destHeight);

	void drawCenteredString(Font *font, const std::string& text, int32_t x, int32_t y, int32_t colorHash);

    void drawString(Font *font, const std::string& text, int32_t x, int32_t y, int32_t colorHash);
};
