#pragma once

#include "interfaces/IBuildInput.h"
#include "interfaces/ITurnInput.h"
#include "../../math/SmoothFloat.h"
#include "RectangleArea.h"
#include "interfaces/IInputHolder.h"
#include "TouchAreaModel.h"
#include "IncludeExcludeArea.h"
#include "TurnDelta.h"
#include "../../entity/Entity.h"

class UnifiedTurnBuild : public ITurnInput, public IBuildInput {
public:
    int32_t unknown_12;
    uint8_t unknown_16;
    uint32_t unknown_20;
    SmoothFloat smoothFloat; // 24
    uint8_t unknown_36;
    RectangleArea unknown_40;
    RectangleArea unknown_64;
    RectangleArea unknown_88;
    IInputHolder *inputHolder; // 112
    uint32_t unknown_116;
    uint32_t xx; // 120
    uint32_t yy; // 124
    bool hasPointerId; // 128
    TouchAreaModel touchAreaModel; // 132
    IncludeExcludeArea includeExcludeArea; // 148
    uint32_t unknown_180;
    float time; // 184
    uint32_t unknown_188;
    float x; // 192
    float y; // 196
    Entity *player; // 200
    float unknown_204;
    uint32_t unknown_208;
    uint8_t unknown_212;
    uint32_t unknown_216;

    UnifiedTurnBuild(int32_t xx, int32_t width, int32_t height, float x, float y, IInputHolder *inputHolder);

    static float getSpeedSquared(Entity *entity);

    TurnDelta getTurnDelta();

    bool isInsideArea(float x, float y);

    void setScreenSize(int32_t width, int32_t height);

    bool tickBuild(void *player, void *buildActionIntention);
};