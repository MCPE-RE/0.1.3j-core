#pragma once

#include "Button.h"
#include "ImageDef.h"

class ImageButton : public Button {
public:
    ImageDef imageDef; // 56

    ImageButton(int32_t buttonId, const std::string& name);

    ImageButton(int32_t buttonId, const std::string& name, ImageDef& imageDef);

    virtual bool isSecondImage(bool second);

    virtual void render(Minecraft *mc, int32_t x, int32_t y);

    virtual void renderBg(Minecraft *mc, int32_t x, int32_t y);

    void setImageDef(ImageDef& imageDef, bool setResolution);

    virtual void setupDefault(void);
};