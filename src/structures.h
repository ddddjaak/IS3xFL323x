// Prevent weirdness from including header more than once
#ifndef __STRUCTURES_H
#define __STRUCTURES_H

struct Digit
{
    union{
        struct
        {
            uint8_t a;
            uint8_t b;
            uint8_t c;
            uint8_t d;
            uint8_t e;
            uint8_t f;
            uint8_t g;
            uint8_t dp;
        };
        uint8_t raw[8];
    };

    /// Array access operator to index into the crgb object
    inline uint8_t& operator[] (uint8_t x) __attribute__((always_inline))
    {
        return raw[x];
    }

    /// Array access operator to index into the crgb object
    inline const uint8_t& operator[] (uint8_t x) const __attribute__((always_inline))
    {
        return raw[x];
    }

    // default values are UNINITIALIZED
    inline Digit() __attribute__((always_inline))
    {
    }

    /// allow construction from abcdefgdp
    inline Digit(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f, uint8_t g, uint8_t dp)  __attribute__((always_inline)) : a(a), b(b), c(c), d(d), e(e), f(f), g(g), dp(dp)
    {
    }
};

struct RGB
{
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

    // Default constructor
    inline RGB() __attribute__((always_inline))
    {
    }

    // Allow construction from R, G, B input values
    inline RGB(uint8_t ir, uint8_t ig, uint8_t ib)  __attribute__((always_inline)) : r(ir), g(ig), b(ib)
    {
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

struct Pixel
{
    union
    {
        struct
        {
            union
            {
                uint8_t rC;
                uint8_t rChannel;
                uint8_t redChannel;
            };
            union
            {
                uint8_t gC;
                uint8_t gChannel;
                uint8_t greenChannel;
            };
            union
            {
                uint8_t bC;
                uint8_t bChannel;
                uint8_t blueChannel;
            };
        };
        uint8_t raw[3];
    };

    RGB pixel;

    // Default values
    inline Pixel() __attribute__((always_inline))
    {
    }

    // Allow construction from channels
    inline Pixel(uint8_t red, uint8_t green, uint8_t blue)  __attribute__((always_inline)) : rC(red), gC(green), bC(blue)
    {
    }

    // Allow assignment from one Pixel struct to another
    inline Pixel& operator= (const Pixel& p) __attribute__((always_inline))
    {
        pixel.r = p.pixel.r;
        pixel.g = p.pixel.g;
        pixel.b = p.pixel.b;
        return *this;
    }

    // Allow assignment from RGB struct to Pixel RGB struct
    inline Pixel& operator= (const RGB& rgb) __attribute__((always_inline))
    {
        pixel.r = rgb.r;
        pixel.g = rgb.g;
        pixel.b = rgb.b;
        return *this;
    }

    // Allow assignment from R, G, and B input values
    inline Pixel& setRGB (uint8_t red, uint8_t green, uint8_t blue) __attribute__((always_inline))
    {
        pixel.r = red;
        pixel.g = green;
        pixel.b = blue;
        return *this;
    }

    // // Allow assignment from R, G, and B input values
    // inline Pixel& r (uint8_t red) __attribute__((always_inline))
    // {
    //     pixel.r = red;
    //     return *this;
    // }

    // Allow assignment from HTMLColorCode input values
    inline Pixel& operator= (const uint32_t colorcode) __attribute__((always_inline))
    {
        pixel.r = (colorcode >> 16) & 0xFF;
        pixel.g = (colorcode >>  8) & 0xFF;
        pixel.b = (colorcode >>  0) & 0xFF;
        return *this;
    }

    // /// subtract a constant of '1' from each channel, saturating at 0x00
    // inline Pixel& operator-- ()  __attribute__((always_inline))
    // {
    //     pixel.r = qsub8( r, 1);
    //     pixel.g = qsub8( g, 1);
    //     pixel.b = qsub8( b, 1);
    //     return *this;
    // }

    // /// add a constant of '1' from each channel, saturating at 0xFF
    // inline Pixel& operator++ ()  __attribute__((always_inline))
    // {
    //     pixel.r = qadd8( r, 1);
    //     pixel.g = qadd8( g, 1);
    //     pixel.b = qadd8( b, 1);
    //     return *this;
    // }
};

typedef Digit FxSevenSegDisplay[];
typedef Pixel FxRGB[];

#endif
// End of __STRUCTURES_H