// Prevent weirdness from including header more than once
#ifndef __CHIPSETS_H
#define __CHIPSETS_H

// #define IS_FL3236A

#define IS31FL3236	FL3236
#define IS31FL3236A	FL3236A
#define IS31FL3237	FL3237
#define IS32FL3237	FL3237

enum Chipsets{FL3236, FL3236A, FL3237};

// #ifdef FL3236
// #pragma GCC poison setFrequency
// #endif

#ifndef IS_FL3236
#ifndef HAS_FREQ_CONTROL
#define HAS_FREQ_CONTROL
#else
#undef HAS_FREQ_CONTROL
#endif
#endif

#ifdef IS_FL3237
#ifndef HAS_PHASE_DELAY
#define HAS_PHASE_DELAY
#else
#undef HAS_PHASE_DELAY
#endif
#endif

#endif
// End of __CHIPSETS_H