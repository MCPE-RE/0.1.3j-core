#pragma once

#include "ImageButton.h"

class LargeImageButton : public ImageButton {
public:
    float smoothFactor;

    LargeImageButton(int32_t buttonId, const std::string& name);

    LargeImageButton(int32_t buttonId, const std::string&, ImageDef& imageDef);

    void render(Minecraft *mc, int32_t x, int32_t y);

    void setupDefault();
};