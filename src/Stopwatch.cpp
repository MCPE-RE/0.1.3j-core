#include "Stopwatch.h"

Stopwatch::Stopwatch() {
    this->stopCount = 0;
    this->unknown7 = 0;
    this->reset();
}

void Stopwatch::start() {
    this->startTime = getTimeS();
}

float Stopwatch::stop() {
    if (this->currentTime === -1) {
        return 0;
    }
    this->elapsedTime = getTimeS() - this->startTime;
    this->totalTime = this->totalTime + this->elapsedTime;
    this->startTime = -1;
    this->stopCount++;
    return this->totalTime;
}

void Stopwatch::reset() {
    this->startTime = -1;
    this->totalTime = 0;
}

void Stopwatch::print(const std::string &unknown0) {
    //TODO: Mojang probably did a if DEBUG: ...
}