#pragma once

#include <cstdint>

class LicenseCodes {
public:
    static bool isOk(int32_t code);

    static bool isReady(int32_t code);
};
