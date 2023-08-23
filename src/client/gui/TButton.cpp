#include "TButton.h"
#include "../../Minecraft.h"

Touch::TButton::TButton(int32_t buttonId, int32_t x, int32_t y, int32_t width, int32_t height, const std::string& name) :
    Button(buttonId, x, y, width, height, name) {
    this->width = 66;
    this->height = 26;
}

Touch::TButton::TButton(int32_t buttonId, int32_t x, int32_t y, const std::string& name) :
    Button(buttonId, x, y, name) {
    this->width = 66;
    this->height = 26;
}

Touch::TButton::TButton(int32_t buttonId, const std::string& name) :
    Button(buttonId, name) {
    this->width = 66;
    this->height = 26;
}

void Touch::TButton::renderBg(Minecraft *mc, int32_t x, int32_t y) {
    bool second =
        this->isUsable &&
        mc->isTouchScreen() &&
        this->x <= x &&
        this->y <= y &&
        this->x + this->width > x &&
        this->y + this->height > y;
    mc->textures->loadAndBindTexture("gui/touchgui.png");
    if (this->isUsable) {
        glColor4f(1.0, 1.0, 1.0, 1.0);
    } else {
        glColor4f(0.5, 0.5, 0.5, 1.0);
    }
    int32_t srcX = 0;
    if (second) {
        srcX = 66;
    }
    this->blit(this->x, this->y, srcX, 0, this->width, this->height, 66, 26);
}