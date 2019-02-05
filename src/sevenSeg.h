#ifdef DEC // Prevent warnings if DEC is previously defined
#undef DEC
#endif
#define DEC 10
#ifdef HEX // Prevent warnings if HEX is previously defined
#undef HEX
#endif
#define HEX 16

// Bit order: DP, G, F, E, D, C, B, A
#define _0 0x3F // 00111111
#define _1 0x06 // 00000110
#define _2 0x5B // 01011011
#define _3 0x4F // 01001111
#define _4 0x66 // 01100110
#define _5 0x6D // 01101101
#define _6 0x7D // 01111101
#define _7 0x07 // 00000111
#define _8 0x7F // 01111111
#define _9 0x6F // 01101111
#define _A 0x77 // 01110111
#define _B 0x7C // 01111100
#define _C 0x39 // 00111001
#define _D 0x5E // 01011110
#define _E 0x79 // 01111001
#define _F 0x71 // 01110001

const uint8_t sevenSegCharMap[16] = {
	_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _A, _B, _C, _D, _E, _F
};
