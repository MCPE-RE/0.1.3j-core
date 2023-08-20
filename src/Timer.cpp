#include "Timer.h"
#include "MCTime.h"

#include <cstdint>

Timer::Timer(float tps) {
    this->tickAdjustment = 1.0f;
    this->ticksPerSecond = tps;
    this->timerSpeed = 1.0f;
    this->partialTicks = 0.0f;
    this->lastSyncTime = getTimeMs();
    this->unprocessedTime = this->lastSyncTime;
    this->lastUpdateTime = this->lastSyncTime / 1000.0f;
}

void Timer::advanceTime() {
    int32_t now = getTimeMs();
    int32_t elapsedTimeMs = now - this->lastSyncTime;
    if (elapsedTimeMs > 1000) {
        int32_t unprocessedMs = now - this->unprocessedTime;
        if (now == this->unprocessedTime) {
            unprocessedMs = 1;
            elapsedTimeMs = 1;
        }
        this->tickAdjustment += (((float)elapsedTimeMs / (float)unprocessedMs) - this->tickAdjustment) * 0.2f;
        this->lastSyncTime = now;
        this->unprocessedTime = now;
    }
    if (elapsedTimeMs < 0) {
        this->lastSyncTime = now;
        this->unprocessedTime = now;
    }
    float deltaTime = (((float)now / 1000.0f) - this->lastUpdateTime) * this->tickAdjustment;
    this->lastUpdateTime = (float)now / 1000.0f;
    if (deltaTime < 0.0f) {
        deltaTime = 0.0f;
    }
    if (deltaTime > 1.0f) {
        deltaTime = 1.0f;
    }
    this->partialTicks += (this->timerSpeed * deltaTime) * this->ticksPerSecond;
    this->ticks = (int32_t)this->partialTicks;
    this->partialTicks -= (float)this->ticks;
    if (this->ticks > 10) {
        this->ticks = 10;
    }
    this->renderTicks = this->partialTicks;
}