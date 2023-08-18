#pragma once

#include <cstdint>
#include <iostream>

class SoundDesc {
public:
    uint8_t *sampleData;
    int32_t sampleDataSize;
    int32_t channels;
    int32_t frameSize;
    int32_t sampleRate;
    int32_t frames;
    std::string name;
    uint8_t *rawData;

    SoundDesc(const SoundDesc& soundDesc);

    SoundDesc(uint8_t *rawData);
};