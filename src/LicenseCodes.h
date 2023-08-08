#ifndef LICENSECODES_H_
#define LICENSECODES_H_

#include <cstdint>

class LicenseCodes {
public:
    static bool isOk(int32_t code);

    static bool isReady(int32_t code);
};

#endif /* LICENSECODES_H_ */
