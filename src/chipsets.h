// Prevent weirdness from including header more than once
#ifndef __CHIPSETS_H
#define __CHIPSETS_H

// #define IS_FL3236A

// #define IS31FL3236	FL3236
// #define IS31FL3236A	FL3236A
// #define IS31FL3237	FL3237
// #define IS32FL3237	FL3237

enum Chipsets{FL3236, FL3236A};

// class Controller {
// // protected:
//  //    CRGB *m_Data;

//  //    virtual void showColor(const struct CRGB & data, int nLeds, CRGB scale) = 0;
// 	// virtual void show(const struct CRGB *data, int nLeds, CRGB scale) = 0;

// public:
// 	/// create an led controller object, add it to the chain of controllers
//     Controller() {

//     }

// 	///initialize the LED controller
// 	virtual void init() = 0;
// };

// template <uint8_t temp=0> class FxLEDController : public Controller {
// public:
// 	FxLEDController() : Controller() {}
// };

// template <uint8_t temp=0> class FL3236Controller : public FxLEDController<> {
// public:
// 	FL3236Controller() {}
// 	virtual void init() {}
// };

// template <uint8_t temp=0> class FL3236AController : public FxLEDController<> {
// public:
// 	FL3236AController() {}
// 	virtual void init() {}
// 	// inline FL3236AController& test () __attribute__((always_inline)) {}
// 	void test() {}
// };

// #ifdef FL3236
// #pragma GCC poison setFrequency
// #endif

// #ifndef IS_FL3236
// #ifndef HAS_FREQ_CONTROL
// #define HAS_FREQ_CONTROL
// #else
// #undef HAS_FREQ_CONTROL
// #endif
// #endif

// #ifdef IS_FL3237
// #ifndef HAS_PHASE_DELAY
// #define HAS_PHASE_DELAY
// #else
// #undef HAS_PHASE_DELAY
// #endif
// #endif

#endif
// End of __CHIPSETS_H