#include "UnifiedTurnBuild.h"
#include "../../MCTime.h"
#include "Multitouch.h"
#include <iostream>
#include "../../math/Mth.h"

UnifiedTurnBuild::UnifiedTurnBuild(int32_t xx, int32_t width, int32_t height, float x, float y, IInputHolder *inputHolder) :
    unknown_40(-1.0, -1.0, 0.0, 0.0),
    unknown_64(-1.0, -1.0, 0.0, 0.0),
    unknown_88(-1.0, -1.0, 0.0, 0.0) {
    this->unknown_12 = xx;
    this->unknown_16 = 0;
    this->inputHolder = inputHolder;
    this->xx = 0.0f;
    this->yy = 0.0f;
    this->hasPointerId = false;
    this->unknown_188 = 0;
    this->x = x;
    this->y = y;
    this->player = nullptr;
    this->unknown_216 = 0;
    this->includeExcludeArea.isDeletable = false;
    this->setScreenSize(width, height);
    this->time = getTimeS();
    this->unknown_204 = this->time;
    this->unknown_208 = 0;
    this->unknown_36 = 0;
    this->unknown_212 = 0;
}

float UnifiedTurnBuild::getSpeedSquared(Entity *entity) {
    float speedX = entity->posX - entity->prevPosX;
    float speedY = entity->posY - entity->prevPosY;
    float speedZ = entity->posZ - entity->prevPosZ;
    return (speedX * speedX) + (speedY * speedY) + (speedZ * speedZ);
}

TurnDelta UnifiedTurnBuild::getTurnDelta() {
    int32_t *pointerIds;
    bool hasPointerId = false;
    float dx = 0.0f;
    float dy = 0.0f;
    float xx;
    float yy;
    float time = getTimeS();
    for (int32_t i = 0; i < Multitouch::getActivePointerIds(&pointerIds); ++i) {
        int16_t x = Multitouch::getX(pointerIds[i]);
        int16_t y = Multitouch::getY(pointerIds[i]);
        if (this->touchAreaModel.getPointerId(x, y, pointerIds[i]) == 100) {
            hasPointerId  = true;
            xx = (float)x * 0.5f;
            yy = (float)y * (-0.5f);
            break;
        }
    }
    if ( hasPointerId && !this->hasPointerId) {
        this->time = time;
        this->unknown_188 = 0;
        this->unknown_216 = 1;
        this->unknown_212 = !this->player || (this->getSpeedSquared(this->player) <= 0.01f);
        this->unknown_36 = 0;
    } else if (this->hasPointerId && !hasPointerId) {
        this->unknown_36 = 0;
        this->unknown_216 = 0;
    }
    if (this->unknown_12 == 2 && (this->hasPointerId || hasPointerId)) {
        if (!this->hasPointerId) {
            this->xx = xx;
            this->yy = yy;
        }
        if (hasPointerId) {
            dx = this->y * this->linearTransform(xx - this->xx, 0.0f, 1.0f, false);
            dy = this->y * this->linearTransform(yy - this->yy, 0.0f, 1.0f, false);
            float delta = Mth::abs(dx) + Mth::abs(dy);
            if (this->x < delta) {
                dx = 0.0f;
                dy = 0.0f;
                delta = 0.0f;
            }
            this->unknown_188 += delta;
            if (this->unknown_216 == 1 && this->unknown_188 >= 20.0f) {
                this->unknown_216 = 2;
            }
            if (this->unknown_216 == 1 && (time - this->time) >= 0.04f) {
                if (this->unknown_188 > 20.0f || (this->player && this->getSpeedSquared(this->player) > 0.01f)) {
                    this->unknown_216 = 2;
                } else {
                    this->unknown_216 = 3;
                }
            }
            if (this->unknown_216 == 1) {
                dy = 0.0f;
                dx = 0.0f;
            }
            this->xx = x;
            this->yy = y;
        }
    } else {
        this->unknown_216 = 0;
    }
    if (this->unknown_212) {
        if (this->unknown_216 == 1) {
            this->inputHolder->delta = this->smoothFloat.getNewDeltaValue((time - this->time) / 0.4f, 0.05f);
        } else {
            if (this->unknown_216 == 3) {
                this->inputHolder->delta = this->smoothFloat.getNewDeltaValue(1.0f, 0.25f);
            }
            if (this->unknown_216 == 2) {
                this->inputHolder->delta = this->smoothFloat.getNewDeltaValue(-0.05f, 0.5f);
            }
            if (this->unknown_216 == 0) {
                this->inputHolder->delta = this->smoothFloat.getNewDeltaValue(-0.05f, 0.5f);
            }
        }
    } else {
        this->inputHolder->delta = -0.05f;
    }
    this->hasPointerId = hasPointerId;
    return TurnDelta(dx, dy);
}

bool UnifiedTurnBuild::isInsideArea(float x, float y) {
    return this->includeExcludeArea.isInside(x, y);
}

void UnifiedTurnBuild::setScreenSize(int32_t width, int32_t height) {
    this->unknown_40 = RectangleArea(0.0f, 0.0f, width, height);
    float dx = ((this->unknown_64.x2 - this->unknown_64.x1) * 0.05) + 10.0;
    this->unknown_64.x1 -= dx;
    this->unknown_64.x2 += dx;
    float dy = ((this->unknown_64.y2 - this->unknown_64.y1) * 0.05) + 10.0;
    this->unknown_64.y1 -= dy;
    this->unknown_64.y2 += dy;
    this->includeExcludeArea.clear();
    this->includeExcludeArea.include(&this->unknown_40);
    this->includeExcludeArea.exclude(&this->unknown_64);
    this->includeExcludeArea.exclude(&this->unknown_88);
    this->touchAreaModel.clear();
    this->touchAreaModel.addArea(100, &this->includeExcludeArea);
}

bool UnifiedTurnBuild::tickBuild(Player *player, void *buildActionIntention) {
    if (this->unknown_216 == 3) {
        if (!this->unknown_36) {
            //*buildActionIntention = BuildActionIntention(10);
            this->unknown_36 = 1;
        } else {
            //*buildActionIntention = BuildActionIntention(2);
        }
        return true;
    } else {
        bool result;
        Multitouch::rewind();
        float time = getTimeS();
        this->unknown_16 = 0;
        while (Multitouch::next()) {
            MouseAction *action = Multitouch::getEvent();
            if (action->button) {
                int32_t pointerId = this->touchAreaModel.getPointerId(action);
                if (pointerId == 100) {
                    this->unknown_16 = 1;
                    if (this->unknown_188 > 20.0f || action->buttonState || result) {
                        if (action->buttonState == 1) {
                            this->unknown_204 = time;
                            this->unknown_208 = 0;
                            this->unknown_216 = 1;
                        }
                    } else {
                        float dt = time - this->unknown_204;
                        if (this->unknown_216 <= 1 && dt >= 0.0f && dt < 0.25f) {
                            //*buildActionIntention = BuildActionIntention(1);
                            result = true;
                        }
                        this->unknown_216 = 0;
                    }
                }
            }
        }
        return result;
    }
}