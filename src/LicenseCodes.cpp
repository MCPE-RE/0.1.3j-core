#include "LicenseCodes.h"

bool LicenseCodes::isOk(int32_t code) {
    return code == 1 || code == 0;
}

bool LicenseCodes::isReady(int32_t code) {
    return code >= 0;
}



