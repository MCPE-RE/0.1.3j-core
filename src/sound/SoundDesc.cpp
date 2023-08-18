#include "SoundDesc.h"

SoundDesc::SoundDesc(const SoundDesc& soundDesc) {
    this->sampleData = soundDesc.sampleData;
    this->sampleDataSize = soundDesc.sampleDataSize;
    this->channels = soundDesc.channels;
    this->frameSize = soundDesc.frameSize;
    this->sampleRate = soundDesc.sampleRate;
    this->frames = soundDesc.frames;
    this->name = soundDesc.name;
    this->rawData = soundDesc.rawData;
}

SoundDesc::SoundDesc(uint8_t *rawData) {
    this->rawData = rawData;
    this->channels = ((int32_t *)rawData)[0];
    this->frameSize = ((int32_t *)rawData)[1];
    this->sampleRate = ((int32_t *)rawData)[2];
    this->frames = ((int32_t *)rawData)[3];
    this->sampleDataSize = this->frames * this->frameSize * this->channels;
    this->sampleData = &this->rawData[16];
}