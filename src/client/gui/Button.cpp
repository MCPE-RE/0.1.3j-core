#include "Button.h"
#include "../../Minecraft.h"

Button::Button(int32_t buttonId, int32_t x, int32_t y, int32_t width, int32_t height, const std::string& name) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->name = name;
    this->buttonId = buttonId;
    this->isUsable = true;
    this->doRender = true;
    this->isHovered = false;
    this->isPressed = false;
}

Button::Button(int32_t buttonId, int32_t x, int32_t y, const std::string& name) {
    this->x = x;
    this->y = y;
    this->width = 200;
    this->height = 24;
    this->name = name;
    this->buttonId = buttonId;
    this->isUsable = true;
    this->doRender = true;
    this->isHovered = false;
    this->isPressed = false;
}

Button::Button(int32_t buttonId, const std::string& name) {
    this->width = 200;
    this->height = 24;
    this->x = 0;
    this->y = 0;
    this->name = name;
    this->buttonId = buttonId;
    this->isUsable = true;
    this->doRender = true;
    this->isHovered = false;
    this->isPressed = false;
}

bool Button::clicked(Minecraft *mc, int32_t x, int32_t y) {
    if (
        !this->isUsable ||
        x < this->x || y < this->y ||
        this->x + this->width <= x || this->y + this->height <= y
    ) {
        return false;
    }
    return true;
}

int32_t Button::getYImage(bool isHovered) {
    if (this->isUsable) {
        if (isHovered) {
            return 2;
        }
        return 1;
    }
    return 0;
}

void Button::released(int32_t x, int32_t y) {
    this->isPressed = false;
}

void Button::render(Minecraft *mc, int32_t x, int32_t y) {
    if (this->doRender) {
        bool doHighlight = true;
        if (mc->isTouchScreen()) {
            doHighlight = false;
        } else if (
            !this->isPressed ||
            x < this->x || y < this->y ||
            this->x + this->width <= x || this->y + this->height <= y
        ) {
            doHighlight = false;
        }
        this->renderBg(mc, x, y);
        if (this->isUsable) {
            if (doHighlight || this->isHovered) {
                this->drawCenteredString(mc->font, this->name, this->x + this->width / 2, (this->height - 8) / 2 + this->y, 0xffffa0);
            } else {
                this->drawCenteredString(mc->font, this->name, this->x + this->width / 2, (this->height - 8) / 2 + this->y, 0xe0e0e0);
            }
        } else {
            this->drawCenteredString(mc->font, this->name, this->x + this->width / 2, (this->height - 8) / 2 + this->y, -0x5f5f60);
        }
    }
}

void Button::renderBg(Minecraft *mc, int32_t x, int32_t y) {
    bool doHighlight = true;
    bool isTouch = mc->isTouchScreen();
    if (isTouch) {
        doHighlight = false;
    } else if (
        !this->isPressed ||
        x < this->x || y < this->y ||
        this->x + this->width <= x || this->y + this->height <= y
    ) {
        doHighlight = false;
    }

    mc->textures->loadAndBindTexture("gui/gui.png");
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    int32_t imageY = this->getYImage(doHighlight || this->isHovered);
    this->blit(this->x, this->y, 0, 20 * imageY + 46, this->width / 2, this->height, 0, 20);
    this->blit(this->x + this->width / 2, this->y, 200 - this->width / 2, 20 * imageY + 46, this->width / 2, this->height, 0, 20);
}

void Button::setPressed() {
    this->isPressed = true;
}