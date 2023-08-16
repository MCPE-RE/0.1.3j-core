#pragma once

#include <iostream>

class Mth {
public:
    static float PI;

    static float RAD_TO_GRAD;

    static float RADDEG;
    
    static float Max(float a, float b);

    static int Max(int a, int b);
    
    static float Min(float a, float b);
    
    static int Min(int a, int b);

    static float abs(float x);

    static int abs(int x);

    static float absDecrease(float a, float b, float c);

    static float absMax(float a, float b);
    
    static float absMaxSigned(float a, float b);

    static float atan(float x);

    static float atan2(float y, float x);

    static float clamp(float x, float min, float max);

    static float cos(float x);

    static int floor(float x);

    static void initMth();

    static int intFloorDiv(int a, int b);

    static float invSqrt(float number);

    static float lerp(float v0, float v1, float t);

    static int lerp(int v0, int v1, float t);

    static int random(int max);

    static float random();

    static float sin(float x);

    static float sqrt(float x);
};