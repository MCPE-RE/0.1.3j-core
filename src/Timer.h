#pragma once

#include <cstdint>

class Timer {
public:
    float lastUpdateTime;
    int32_t lastSyncTime;
    int32_t unprocessedTime;
    float tickAdjustment;
    float ticksPerSecond;
    int32_t ticks;
    float renderTicks;
    float timerSpeed;
    float partialTicks;

    Timer(float tps);

    void advanceTime();
};