// Prevent weirdness from including header more than once
#ifndef __STRUCTURES_H
#define __STRUCTURES_H

struct RGB
{
	const uint8_t redChannel;
	const uint8_t greenChannel;
	const uint8_t blueChannel;

    union
    {
        uint8_t r;
        uint8_t red;
    };
    union
    {
        uint8_t g;
        uint8_t green;
    };
    union
    {
        uint8_t b;
        uint8_t blue;
    };

    // Allow assignment from HTMLColorCode
    inline RGB& operator= (const uint32_t colorcode) __attribute__((always_inline))
    {
        r = (colorcode >> 16) & 0xFF;
        g = (colorcode >>  8) & 0xFF;
        b = (colorcode >>  0) & 0xFF;
        return *this;
    }

    // Predefined RGB colors
    typedef enum {
        Black=0x000000,
        Blue=0x0000FF,
        Cyan=0x00FFFF,
        Green=0x00FF00,
        Magenta=0xFF00FF,
        Red=0xFF0000,
        White=0xFFFFFF,
        Yellow=0xFFFF00
    } HTMLColorCode;
};

typedef uint8_t FxSevenSeg[][8];
typedef RGB FxRGB[];

#endif
// End of __STRUCTURES_H