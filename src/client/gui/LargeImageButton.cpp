#include "LargeImageButton.h"
#include "../../math/Mth.h"
#include "../../Minecraft.h"

LargeImageButton::LargeImageButton(int32_t buttonId, const std::string& name) : ImageButton(buttonId, name) {
    this->setupDefault();
}

LargeImageButton::LargeImageButton(int32_t buttonId, const std::string&, ImageDef& imageDef) : ImageButton(buttonId, name) {
    this->imageDef = imageDef;
    this->setupDefault();
}

void LargeImageButton::render(Minecraft *mc, int32_t x, int32_t y) {
    if (this->doRender) {
        glColor4f(1.0, 1.0, 1.0, 1.0);
        bool second =
            this->isUsable &&
            mc->isTouchScreen() &&
            this->x <= x &&
            this->y <= y &&
            this->x + this->width > x &&
            this->y + this->height > y;
        this->renderBg(mc, x, y);
        GLuint textureId = -1;
        if (this->imageDef.name.length()) {
            textureId = mc->textures->loadAndBindTexture(this->imageDef.name);
        }
        if (mc->textures->isTextureIdValid(textureId)) {
            Tesselator::instance.begin();
            if (!this->isUsable) {
                Tesselator::instance.color(0xff808080);
            } else {
                Tesselator::instance.color(0xffffffff);
            }
            float halfImageWidth = this->imageDef.width * 0.5;
            float halfImageHeight = this->imageDef.height * 0.5;
            float imageX = this->x + (float)this->imageDef.x + halfImageWidth;
            float imageY = this->y + (float)this->imageDef.y + halfImageHeight;
            if (second) {
                this->smoothFactor = Mth::Max(0.95f, this->smoothFactor - 0.025f);
            } else {
                this->smoothFactor = Mth::Min(1.0f, this->smoothFactor + 0.025f);
            }
            halfImageWidth *= this->smoothFactor;
            halfImageHeight *= this->smoothFactor;
            if (this->imageDef.doRender) {
                TextureData *data = mc->textures->getTemporaryTextureData(textureId);
                if (data) {
                    float minU = (float)(this->imageDef.rect.minX + (second ? this->imageDef.rect.maxX : 0)) / (float)data->width;
                    float maxU = (float)(this->imageDef.rect.minX + (second ? 2 * this->imageDef.rect.maxX : this->imageDef.rect.maxX)) / (float)data->width;
                    float minV = (float)this->imageDef.rect.minY / (float)data->height;
                    float maxV = (float)(this->imageDef.rect.minY + this->imageDef.rect.maxY) / (float)data->height;
                    Tesselator::instance.vertexUV(imageX - halfImageWidth, imageY - halfImageHeight, this->zCoord, minU, minV);
                    Tesselator::instance.vertexUV(imageX - halfImageWidth, imageY + halfImageHeight, this->zCoord, minU, maxV);
                    Tesselator::instance.vertexUV(imageX + halfImageWidth, imageY + halfImageHeight, this->zCoord, maxU, maxV);
                    Tesselator::instance.vertexUV(imageX + halfImageWidth, imageY - halfImageHeight, this->zCoord, maxU, minV);
                }
            } else {
                Tesselator::instance.vertexUV(imageX - halfImageWidth, imageY - halfImageHeight, this->zCoord, 0.0f, 0.0f);
                Tesselator::instance.vertexUV(imageX - halfImageWidth, imageY + halfImageHeight, this->zCoord, 0.0f, 1.0f);
                Tesselator::instance.vertexUV(imageX + halfImageWidth, imageY + halfImageHeight, this->zCoord, 1.0f, 1.0f);
                Tesselator::instance.vertexUV(imageX + halfImageWidth, imageY - halfImageHeight, this->zCoord, 1.0f, 0.0f);
            }
            Tesselator::instance.draw();
        }
        if (!this->isUsable) {
            this->drawCenteredString(mc->font, this->name, this->x + this->width / 2, this->y + 11, 0xffa0a0a0);
        } else if (second || this->isHovered) {
            this->drawCenteredString(mc->font, this->name, this->x + this->width / 2, this->y + 11, 0xffffa0);
        } else {
            this->drawCenteredString(mc->font, this->name, this->x + this->width / 2, this->y + 11, 0xe0e0e0);
        }
    }
}

void LargeImageButton::setupDefault() {
    this->smoothFactor = 1.0;
    this->width = 80;
    this->height = 90;
}