#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H
#include <inttypes.h>

#define PCG32_INITIALIZER { 0x853c49e6748fea9bULL, 0xda3e39cb94b95bdbULL }
struct pcg_state_setseq_64 {    
    uint64_t state;            
    uint64_t inc;             

};
typedef struct pcg_state_setseq_64 pcg32_random_t;

uint32_t pcg32_random(uint64_t min, uint64_t max);
uint32_t pcg32_random_r(pcg32_random_t * rng);
uint32_t pcg32_srandom_r(pcg32_random_t * rng, uint64_t initstate, uint64_t initseq);
uint32_t pcg32_srandom(uint64_t seed, uint64_t seq);

#endif
