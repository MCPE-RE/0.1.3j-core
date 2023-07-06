#ifndef STOPWATCH_H_
#define STOPWATCH_H_

#include <cstdint>
#include <string>
#include "MCTime.h"

class Stopwatch {
public:
    float startTime;  // 0
    float totalTime;  // 4
    float elapsedTime; // 8
    uint32_t stopCount; // 12
    uint32_t unknown7; // 16

    Stopwatch();

    float stop();

    void print(const std::string &identifier);
    
    void reset();

    void start();
};

#endif