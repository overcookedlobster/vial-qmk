#include QMK_KEYBOARD_H
#include "gombalan.h"
#include "bitmap_data.h"

#ifdef VIAL_ENABLE
#include "vial.h"
#endif

#define CHAR_DELAY 50
#define MAX_CHARS_PER_LINE 21
#define MAX_LINES 4

static uint16_t char_timer = 0;
static uint8_t current_char = 0;
static char current_advice[100] = {0};
static bool advice_completed = false;
static bool new_advice_needed = true;
static uint32_t startup_timer = 0;
static bool initial_display = true;

// Define custom keycodes for encoder buttons
enum custom_keycodes {
    ENC1_BTN = SAFE_RANGE,
    ENC2_BTN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_base(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END, ENC1_BTN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,ENC2_BTN,
        LSFT_T(KC_GRV),   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT,   MO(1), KC_LEFT, KC_DOWN, KC_RGHT ),

    [1] = LAYOUT_base(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,  KC_DEL, KC_HOME,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT )
};

void oled_show_random_advice(void) {
    static uint8_t line = 0;
    static uint8_t col = 0;
    static uint16_t word_end = 0;

    if (new_advice_needed) {
        char_timer = timer_read();
        current_char = 0;
        line = 0;
        col = 0;
        word_end = 0;
        advice_completed = false;
        int random_index = rand() % ADVICE_COUNT;
        strncpy(current_advice, advice_list[random_index], sizeof(current_advice) - 1);
        current_advice[sizeof(current_advice) - 1] = '\0';
        oled_clear();
        new_advice_needed = false;
    }

    if (!advice_completed && current_char < strlen(current_advice)) {
        if (timer_elapsed(char_timer) > CHAR_DELAY) {
            char_timer = timer_read();

            if (current_char >= word_end) {
                for (word_end = current_char; word_end < strlen(current_advice); word_end++) {
                    if (current_advice[word_end] == ' ' || word_end == strlen(current_advice) - 1) {
                        break;
                    }
                }
            }

            if (col == 0 || (col + (word_end - current_char + 1) <= MAX_CHARS_PER_LINE)) {
                oled_set_cursor(col, line);
                oled_write_char(current_advice[current_char], false);
                col++;

                if (col >= MAX_CHARS_PER_LINE || current_advice[current_char] == '\n') {
                    line++;
                    col = 0;
                    if (line >= MAX_LINES) {
                        advice_completed = true;
                        return;
                    }
                }

                current_char++;
            } else {
                line++;
                col = 0;
                if (line >= MAX_LINES) {
                    advice_completed = true;
                    return;
                }
            }

            if (current_char == strlen(current_advice)) {
                advice_completed = true;
            }
        }
    }
}

void change_advice(void) {
    new_advice_needed = true;
    advice_completed = false;
    oled_clear();
}

bool oled_task_user(void) {
    if (!is_keyboard_master()) return false;

    if (initial_display) {
        if (startup_timer == 0) {
            startup_timer = timer_read32();
            oled_clear();
            oled_write_raw_P(image_bitmap, sizeof(image_bitmap));
        }

        if (timer_elapsed32(startup_timer) > 4000) {
            initial_display = false;
            oled_clear();
            new_advice_needed = true;
        }
        return false;
    }

    #ifdef VIAL_ENABLE
    if (!vial_unlock_in_progress) {
        oled_show_random_advice();
    }
    #else
    oled_show_random_advice();
    #endif

    return false;
}

void keyboard_post_init_user(void) {
    srand(timer_read());
    oled_init(OLED_ROTATION_180);
    initial_display = true;
    startup_timer = 0;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef VIAL_ENABLE
    if (vial_unlock_in_progress) {
        return true;  // Let Vial handle keycodes when unlocking
    }
    #endif

    switch (keycode) {
        case ENC1_BTN:
        case ENC2_BTN:
            if (record->event.pressed) {
                change_advice();
            }
            return false;
        case KC_ENT:
            if (record->event.pressed) {
                if (advice_completed) {
                    change_advice();
                }
                oled_task_user();
            }
            return true;
        default:

            // if (record->event.pressed) {
            //     if (advice_completed) {
            //         change_advice();
            //     }
            //     oled_task_user();
            // }
            return true;
    }
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) }
};
#endif

#ifdef VIAL_ENABLE
// Vial-specific functions
void vial_oled_task_user(void) {
    // This function will be called by Vial when it wants to update the OLED
    // You can add any Vial-specific OLED updates here
}
#endif
