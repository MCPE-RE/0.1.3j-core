#ifndef BUTTON_H_
#define BUTTON_H_

#include <iostream>
#include "GuiComponent.h"
#include <cstdint>

class Minecraft;

class Button : public GuiComponent {
public:
    int32_t width; // 2
    int32_t height; // 3
    int32_t x; // 4
    int32_t y; // 5
    std::string name; // 24
    int32_t buttonId; // 12
    bool isUsable; // 52
    bool doRender; // 53
    bool isHovered; // 54
    bool isPressed; // 55

    Button(int32_t buttonId, int32_t x, int32_t y, int32_t width, int32_t height, const std::string& name);

    Button(int32_t buttonId, int32_t x, int32_t y, const std::string& name);

    bool clicked(Minecraft *mc, int32_t x, int32_t y);

    int32_t getYImage(bool isHovered);

    void released(int32_t x, int32_t y);

    void render(Minecraft *mc, int32_t x, int32_t y);

    void renderBg(Minecraft *mc, int32_t x, int32_t y);

    void setPressed();
    
};

#endif
