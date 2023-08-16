#pragma once

#include <cstdint>

// http://www.math.sci.hiroshima-u.ac.jp/m-mat/MT/MT2002/CODES/mt19937ar.c

/* Period parameters */  
#define MTR_N 624
#define MTR_M 397
#define MTR_MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define MTR_UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define MTR_LOWER_MASK 0x7fffffffUL /* least significant r bits */

class Random {
public:
    int32_t seed;
    uint32_t mt[MTR_N]; /* the array for the state vector  */
    int32_t mti; /* mti==N+1 means mt[N] is not initialized */

    Random(int32_t seed);

    Random();

    int32_t genrand_int32();

    float genrand_real2();

    void init_genrand(uint32_t s);

    float nextFloat();

    int32_t nextInt(int32_t max);

    int32_t nextInt();

    int32_t nextLong();

    void setSeed(int32_t seed);
};