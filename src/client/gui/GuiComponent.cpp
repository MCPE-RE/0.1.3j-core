#include "GuiComponent.h"
#include "../renderer/Tesselator.h"
#ifdef USE_DESKTOP_GL
#include <glad/gl.h>
#else
#include <GLES/gl.h>
#endif

GuiComponent::GuiComponent() {
	this->zCoord = 0.0f;
}

void GuiComponent::fill(int32_t leftEdge, int32_t topEdge, int32_t rightEdge, int32_t bottomEdge, int32_t fillColor) {
	glEnable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(
		(fillColor >> 16 & 0xFF) / 255.0f,
		(fillColor >> 8 & 0xFF) / 255.0f,
		(fillColor & 0xFF) / 255.0f,
		((uint32_t)fillColor >> 24) / 255.0f
	);
	Tesselator::instance.begin();
	Tesselator::instance.vertex(leftEdge, bottomEdge, 0.0f);
	Tesselator::instance.vertex(rightEdge, bottomEdge, 0.0f);
	Tesselator::instance.vertex(rightEdge, topEdge, 0.0f);
	Tesselator::instance.vertex(leftEdge, topEdge, 0.0f);
	Tesselator::instance.draw();
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

void GuiComponent::fillGradient(int32_t xLeft, int32_t yTop, int32_t xRight, int32_t yBottom, int32_t colorTop, int32_t colorBottom) {
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glDisable(GL_ALPHA_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glShadeModel(GL_SMOOTH);
    Tesselator::instance.begin();
    Tesselator::instance.color(
        (colorTop >> 16 & 0xFF) / 255.0f,
        (colorTop >> 8 & 0xFF) / 255.0f,
        (colorTop & 0xFF) / 255.0f,
        ((uint32_t)colorTop >> 24) / 255.0f
    );
    Tesselator::instance.vertex(xRight, yTop, 0.0f);
    Tesselator::instance.vertex(xLeft, yTop, 0.0f);
    Tesselator::instance.color(
        (colorBottom >> 16 & 0xFF) / 255.0f,
        (colorBottom >> 8 & 0xFF) / 255.0f,
        (colorBottom & 0xFF) / 255.0f,
        ((uint32_t)colorBottom >> 24) / 255.0f
    );
    Tesselator::instance.vertex(xLeft, yBottom, 0.0f);
    Tesselator::instance.vertex(xRight, yBottom, 0.0f);
    Tesselator::instance.draw();
    glShadeModel(GL_FLAT);
    glDisable(GL_BLEND);
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_TEXTURE_2D);
}

void GuiComponent::blit(int32_t x, int32_t y, int32_t srcX, int32_t srcY, int32_t srcWidth, int32_t srcHeight, int32_t destWidth, int32_t destHeight) {
	if (!destWidth) {
		destWidth = srcWidth;
	}
	if (!destHeight) {
		destHeight = srcHeight;
	}
	Tesselator::instance.begin();
	Tesselator::instance.vertexUV(
		(float)x,
		(float)(srcHeight + y),
		this->zCoord,
		(float)srcX * 0.0039062,
		(float)(destHeight + srcY) * 0.0039062
	);
	Tesselator::instance.vertexUV(
		(float)(srcWidth + x),
		(float)(srcHeight + y),
		this->zCoord,
		(float)(destWidth + srcX) * 0.0039062,
		(float)(destHeight + srcY) * 0.0039062
	);
	Tesselator::instance.vertexUV(
		(float)(srcWidth + x),
		(float)y,
		this->zCoord,
		(float)(destWidth + srcX) * 0.0039062,
		(float)srcY * 0.0039062
	);
	Tesselator::instance.vertexUV(
		(float)x,
		(float)y,
		this->zCoord,
		(float)srcX * 0.0039062,
		(float)srcY * 0.0039062
	);
	Tesselator::instance.draw();
}

void GuiComponent::drawCenteredString(Font *font, const std::string& text, int32_t x, int32_t y, int32_t colorHash) {
    int32_t width = font->width(text);
    int32_t height = font->height(text);
    font->drawShadow(text, x - width / 2, y - height / 2, colorHash);
}

void GuiComponent::drawString(Font *font, const std::string& text, int32_t x, int32_t y, int32_t colorHash) {
    font->drawShadow(text, x, y, colorHash);
}

GuiComponent::~GuiComponent() {
	// TODO Auto-generated destructor stub
}
