#include "BuyButton.h"
#include "../../Minecraft.h"

BuyButton::BuyButton(int32_t buttonId) : ImageButton(buttonId, "") {
    ImageDef imageDef;
    imageDef.rect.minX = 64;
    imageDef.rect.minY = 182;
    imageDef.rect.maxX = 190;
    imageDef.rect.maxY = 55;
    imageDef.doRender = true;
    imageDef.width = 75.0f;
    imageDef.height = 21.711f;
    imageDef.name = "gui/gui.png";
    this->setImageDef(imageDef, true);
}

void BuyButton::render(Minecraft *mc, int32_t x, int32_t y) {
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
            } else if (second || this->isHovered) {
                Tesselator::instance.color(0xffcccccc);
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
            TextureData *data = mc->textures->getTemporaryTextureData(textureId);
            if (data) {
                float minU = (float)this->imageDef.rect.minX / (float)data->width;
                float maxU = (float)(this->imageDef.rect.minX + this->imageDef.rect.maxX) / (float)data->width;
                float minV = (float)this->imageDef.rect.minY / (float)data->height;
                float maxV = (float)(this->imageDef.rect.minY + this->imageDef.rect.maxY) / (float)data->height;
                Tesselator::instance.vertexUV(imageX - halfImageWidth, imageY - halfImageHeight, this->zCoord, minU, minV);
                Tesselator::instance.vertexUV(imageX - halfImageWidth, imageY + halfImageHeight, this->zCoord, minU, maxV);
                Tesselator::instance.vertexUV(imageX + halfImageWidth, imageY + halfImageHeight, this->zCoord, maxU, maxV);
                Tesselator::instance.vertexUV(imageX + halfImageWidth, imageY - halfImageHeight, this->zCoord, maxU, minV);
            }
            Tesselator::instance.draw();
        }
    }
}