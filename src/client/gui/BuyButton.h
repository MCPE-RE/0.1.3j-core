#pragma once

#include "ImageButton.h"

class BuyButton : public ImageButton {
public:
    BuyButton(int32_t buttonId);

    void render(Minecraft *mc, int32_t x, int32_t y);
};