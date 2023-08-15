#include "Mth.h"
#include <cmath>

static float MthSinTable[65536];

float Mth::PI = 3.1415927f;
float Mth::RAD_TO_GRAD = 0.017453292f;
float Mth::RADDEG = 57.295776f;

float Mth::Max(float a, float b) {
    return a < b ? b : a;
}

int Mth::Max(int a, int b) {
    return a < b ? b : a;
}
    
float Mth::Min(float a, float b) {
    return a > b ? b : a;
}
    
int Mth::Min(int a, int b) {
    return a > b ? b : a;
}

float Mth::abs(float x) {
    return x < 0.0f ? -x : x;
}

int Mth::abs(int x) {
    return (int)Mth::abs((float)x);
}

float Mth::absDecrease(float a, float b, float c) {
    return a <= 0.0f ? Mth::Min(a + b, -c) : Mth::Max(a - b, c);
}

float Mth::absMax(float a, float b) {
    if (a < 0.0f) {
        a = -a;
    }
    if (b < 0.0f) {
        b = -b;
    }
    return a <= b ? b : a;
}
    
float Mth::absMaxSigned(float a, float b) {
    return Mth::abs(a) <= Mth::abs(b) ? b : a;
}

float Mth::atan(float x) {
    return atanf(x);
}

float Mth::atan2(float y, float x) {
    return atan2f(y, x);
}

float Mth::clamp(float x, float min, float max) {
    if (x > max) {
        return max;
    }
    if (x <= min) {
        return min;
    }
    return x;
}

float Mth::cos(float x) {
    return MthSinTable[(int)((x * 10430.0f) + 16384.0f) & 0xFFFF];
}

int Mth::floor(float x) {
    return ((float)((int)x) <= x) ? (int)x : (int)x - 1;
}

void Mth::initMth() {
    for (int i = 0; i < 65536; ++i) {
        MthSinTable[i] = sinf((float)i / 10430.0f);
    }
}

int Mth::intFloorDiv(int a, int b) {
    return a >= 0 ? a / b : ~(~a / b);
}

// https://en.wikipedia.org/wiki/Fast_inverse_square_root#Overview_of_the_code
float Mth::invSqrt(float number) {
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y;                       // evil floating point bit level hacking
    i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
    y  = * ( float * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
    // y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

    return y;
}

float Mth::lerp(float v0, float v1, float t) {
    return v0 + t * (v1 - v0);
}

int Mth::lerp(int v0, int v1, float t) {
    return v0 + (int)(t * (float)(v1 - v0));
}

int Mth::random(int seed) {}

float Mth::random() {}

float Mth::sin(float x) {
    return MthSinTable[(int)(x * 10430.0f) & 0xFFFF];
}

float Mth::sqrt(float x) {
    return sqrtf(x);
}