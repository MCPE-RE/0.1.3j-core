#include "ImageButton.h"
#include "../../Minecraft.h"

ImageButton::ImageButton(int32_t buttonId, const std::string& name) : Button(buttonId, name) {
    this->setupDefault();
}

ImageButton::ImageButton(int32_t buttonId, const std::string& name, ImageDef& imageDef) : Button(buttonId, name) {
    this->imageDef = imageDef;
    this->setupDefault();
}

bool ImageButton::isSecondImage(bool second) {
    return second;
}

void ImageButton::render(Minecraft *mc, int32_t x, int32_t y) {
    if (this->doRender) {
        glColor4f(1.0, 1.0, 1.0, 1.0);
        bool second =
            this->isUsable &&
            mc->isTouchScreen() &&
            this->x <= x &&
            this->y <= y &&
            this->x + this->width > x &&
            this->y + this->height > x;
        bool isSecond = this->isSecondImage(second);
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
                halfImageWidth *= 0.95;
                halfImageHeight *= 0.95;
            }
            if (this->imageDef.doRender) {
                TextureData *data = mc->textures->getTemporaryTextureData(textureId);
                if (data) {
                    float minU = (float)(this->imageDef.rect.minX + (isSecond ? this->imageDef.rect.maxX : 0)) / (float)data->width;
                    float maxU = (float)(this->imageDef.rect.minX + (isSecond ? 2 * this->imageDef.rect.maxX : this->imageDef.rect.maxX)) / (float)data->width;
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
            this->drawCenteredString(mc->font, this->name, this->x + this->width / 2, this->y + 16, 0xffa0a0a0);
        } else if (second || this->isHovered) {
            this->drawCenteredString(mc->font, this->name, this->x + this->width / 2, this->y + 17, 0xffffa0);
        } else {
            this->drawCenteredString(mc->font, this->name, this->x + this->width / 2, this->y + 16, 0xe0e0e0);
        }
    }
}

void ImageButton::renderBg(Minecraft *mc, int32_t x, int32_t y) {}

void ImageButton::setImageDef(ImageDef& imageDef, bool setResolution) {
    this->imageDef = imageDef;
    if (setResolution) {
        this->width = (int32_t)imageDef.width;
        this->height = (int32_t)imageDef.height;
    }
}

void ImageButton::setupDefault(void) {
    this->width = 80;
    this->height = 90;
}