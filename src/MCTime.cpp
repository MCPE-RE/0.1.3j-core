#include "MCTime.h"
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif
#include <cstdint>

static float mcEpoch = (float)time(NULL);

float getTimeS(void) {
    #ifndef _WIN32
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((float)tv.tv_sec - mcEpoch) + ((float)tv.tv_usec / 1000000.0f);
    #else
    SYSTEMTIME current_systemtime;
    FILETIME current_timestamp;
    GetSystemTime(&current_systemtime);
    SystemTimeToFileTime(&current_systemtime, &current_timestamp);
    return ((float)((*(uint64_t *)&current_timestamp) - 116444736000000000) / 10000000.0f) - mcEpoch;
    #endif
}

int32_t getTimeMs() {
  return (int32_t)(getTimeS() * 1000.0f);
}