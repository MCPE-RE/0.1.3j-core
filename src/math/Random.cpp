#include "Random.h"
#include "../MCTime.h"

// http://www.math.sci.hiroshima-u.ac.jp/m-mat/MT/MT2002/CODES/mt19937ar.c

Random::Random(int32_t seed) {
    this->setSeed(seed);
}

Random::Random() {
    this->setSeed(getTimeS());
}

int32_t Random::genrand_int32() {
    uint32_t y;
    static uint32_t mag01[2] = {0x0UL, MTR_MATRIX_A};
    /* mag01[x] = x * MATRIX_A  for x=0,1 */

    if (this->mti >= MTR_N) { /* generate N words at one time */
        int kk;

        if (this->mti == MTR_N + 1)   /* if init_genrand() has not been called, */
            this->init_genrand(5489UL); /* a default initial seed is used */

        for (kk = 0; kk < MTR_N - MTR_M; kk++) {
            y = (this->mt[kk] & MTR_UPPER_MASK) | (this->mt[kk + 1] & MTR_LOWER_MASK);
            this->mt[kk] = this->mt[kk + MTR_M] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        for (; kk < MTR_N - 1; kk++) {
            y = (this->mt[kk] & MTR_UPPER_MASK) | (this->mt[kk + 1] & MTR_LOWER_MASK);
            this->mt[kk] = this->mt[kk + (MTR_M - MTR_N)] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        y = (this->mt[MTR_N - 1] & MTR_UPPER_MASK) | (this->mt[0] & MTR_LOWER_MASK);
        this->mt[MTR_N - 1] = this->mt[MTR_M - 1] ^ (y >> 1) ^ mag01[y & 0x1UL];

        this->mti = 0;
    }
  
    y = this->mt[this->mti++];

    /* Tempering */
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680UL;
    y ^= (y << 15) & 0xefc60000UL;
    y ^= (y >> 18);

    return y;
}

float Random::genrand_real2() {
    return (float)this->genrand_int32() * 2.32830644e-10f;
}

void Random::init_genrand(uint32_t s) {
    this->mt[0] = s & 0xffffffffUL;
    for (this->mti = 1; this->mti < MTR_N; this->mti++) {
        this->mt[this->mti] = (1812433253UL * (this->mt[this->mti - 1] ^ (this->mt[this->mti - 1] >> 30)) + this->mti); 
        /* See Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier. */
        /* In the previous versions, MSBs of the seed affect   */
        /* only MSBs of the array mt[].                        */
        /* 2002/01/09 modified by Makoto Matsumoto             */
        this->mt[mti] &= 0xffffffffUL;
        /* for >32 bit machines */
    }
}

float Random::nextFloat() {
    return this->genrand_real2();
}

int32_t Random::nextInt(int32_t max) {
    return this->genrand_int32() % max;
}

int32_t Random::nextInt() {
    return this->genrand_int32() >> 1;
}

int32_t Random::nextLong() {
    return this->genrand_int32() >> 1;
}

void Random::setSeed(int32_t seed) {
    this->seed = seed;
    this->mti = MTR_N + 1;
    this->init_genrand(seed);
}