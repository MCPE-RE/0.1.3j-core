#pragma once

#include "interfaces/IMoveInput.h"
#include "../gui/GuiComponent.h"
#include "RectangleArea.h"
#include "TouchAreaModel.h"
#include "../../Options.h"
#include "PolygonArea.h"

class Minecraft;

class TouchscreenInput_TestFps : public IMoveInput, public GuiComponent {
public:
    RectangleArea rectangleArea;
    uint8_t uunknown0[10];
    Options *options;
    uint8_t uunknown1;
    uint8_t uunknown2;
    TouchAreaModel touchAreaModel;
    Minecraft *minecraft;
    PolygonArea *button2PolygonArea;
    PolygonArea *button3PolygonArea;
    PolygonArea *button0PolygonArea;
    PolygonArea *button1PolygonArea;
    PolygonArea *button4PolygonArea;
    bool buttonStates[8];

    TouchscreenInput_TestFps(Minecraft *minecraft, Options *options);

    RectangleArea getRectangleArea();

    bool isButtonDown(int32_t button);

    void releaseAllKeys();

    void render(float unknown);

    void setKey(int32_t key, bool isPressed);

    void setScreenSize(int32_t width, int32_t height);
    
    void tick(void *player);
};
