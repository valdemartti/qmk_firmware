/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// #define USE_MATRIX_I2C

/* Select hand configuration */

#define SPLIT_USB_DETECT
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// #define GP12 12U

#define SERIAL_USART_TX_PIN 12U

#define OLED_TIMEOUT 300000

#define TAPPING_TERM 210
#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM 0

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_RGB_TEST
#    define RGBLIGHT_EFFECT_ALTERNATING
#    define RGBLIGHT_EFFECT_TWINKLE
#    define RGBLIGHT_LIMIT_VAL 120
#    define RGBLIGHT_HUE_STEP 10
#    define RGBLIGHT_SAT_STEP 17
#    define RGBLIGHT_VAL_STEP 17
#endif

// #undef RGBLIGHT_DRIVER
// #define RGBLIGHT_DRIVER ws2812
// #undef WS2812_DI_PIN
// #define WS2812_DI_PIN 14U
// #undef RGBLIGHT_LED_COUNT
// #define RGBLIGHT_LED_COUNT 27
// #undef RGBLED_SPLIT
// #define RGBLED_SPLIT { 27, 0 }

// #undef RGBLIGHT_LIMIT_VAL
// #define RGBLIGHT_LIMIT_VAL 255
// #undef RGBLIGHT_HUE_STEP
// #define RGBLIGHT_HUE_STEP 8
// #undef RGBLIGHT_DEFAULT_MODE
// #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
// #undef RGBLIGHT_DEFAULT_HUE
// #define RGBLIGHT_DEFAULT_HUE 0
// #undef RGBLIGHT_DEFAULT_ON
// #define RGBLIGHT_DEFAULT_ON true

#undef WS2812_DI_PIN
#define WS2812_DI_PIN 25
#undef RGBLIGHT_LED_COUNT
#define RGBLIGHT_LED_COUNT 29
#undef RGBLED_SPLIT
#define RGBLED_SPLIT { 28, 1 }