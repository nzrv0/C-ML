#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <inttypes.h>
#include "random_generator.h" 

// basic implimentation of pcg algortihm

/*
 * linear congruential generator (LCG)
 * X_n+1 = (X*a +b ) % m
 * 0 < m - modul
 * 0 < a < m - mutliplayer
 * 0 <= b < m - increment
 * 0 <= X < m - seed
*/

static pcg32_global = PCG32_INITIALIZER;

uint32_t pcg32_random_r(pcg32_random_t * rng) {
    uint64_t oldstate = rng->state;
    uint64_t mult = 6364136223846793005ULL;
    rng->state = oldstate * mult + (rng->inc);
    uint32_t xorshifted = ((oldstate >> 18u) ^ oldstate) >> 27u;
    uint32_t rot = oldstate >> 59u;
    return (xorshifted >> rot) | (xorshifted << ((-rot) & 31));
}

uint32_t pcg32_random(){
    return pcg32_random_r(&pcg32_global);
}


uint32_t pcg32_srandom_r(pcg32_random_t * rng, uint64_t initstate, uint64_t initseq)
{
    rng->state = 0U;
    rng->inc = (initseq << 1u) | 1u;
    pcg32_random_r(rng);
    rng->state += initstate;
    pcg32_random_r(rng);
}

uint32_t pcg32_srandom(uint64_t seed, uint64_t seq){
    pcg32_srandom_r(&pcg32_global, seed, seq);
}
