#pragma once

#define VIAL_KEYBOARD_UID {0x8C, 0x59, 0x2E, 0xF7, 0xBA, 0x40, 0xCC, 0xCA}

#undef ENCODERS_PAD_A
#undef ENCODERS_PAD_B
#define ENCODERS_PAD_A { D4, F4 }
#define ENCODERS_PAD_B { C6, F5 }

#define VIAL_COMBO_ENTRIES 2
#define VIAL_TAP_DANCE_ENTRIES 4
#define VIAL_KEY_OVERRIDE_ENTRIES 2
#define DYNAMIC_KEYMAP_LAYER_COUNT 2

#define VIAL_UNLOCK_COMBO_ROWS { 0, 4 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 14 }

#define VIAL_ENCODER_DEFAULT { KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }

// OLED setup
#define OLED_TIMEOUT 60000
#define OLED_BRIGHTNESS 128

// Animation Configuration
#define IDLE_FRAMES 5
#define IDLE_SPEED 30
#define TAP_FRAMES 2
#define TAP_SPEED 40
#define ANIM_FRAME_DURATION 200
#define ANIM_SIZE 512
