// Copyright 2021 JasonRen(biu)
// Copyright 2022 Drashna Jael're (@Drashna Jael're)
// Copyright 2024 Uno-Sebastian
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// User defined enums for layers
#define _QWERTY 0
#define _NUMP 1
#define _FUNC 2  


#define AUTO_SHIFT_TIMEOUT 175 // Auto shift timeout (in milliseconds)
// #define TAPPING_TERM 200 // Tapping term (in milliseconds)

// Custom shorthand for right shift + keyboard minus
#define R_UNSCR RSFT(KC_MINS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌──────┬───┬───┬───┬───┬───┬───┐                     ┌───┬───┬───┬───┬───┬───┬──────┐
     * │Escape│ 1 │ 2 │ 3 │ 4 │ 5 │ + │                     │ - │ 6 │ 7 │ 8 │ 9 │ 0 │    ` │
     * ├──────┼───┼───┼───┼───┼───┼───┤                     ├───┼───┼───┼───┼───┼───┼──────┤
     * │ Del  │ Q │ W │ E │ R │ T │ = │                     │ _ │ Y │ U │ I │ O │ P │    \ │
     * ├──────┼───┼───┼───┼───┼───┤   │                     │   ├───┼───┼───┼───┼───┼──────┤
     * │ Bsp  │ A │ S │ D │ F │ G ├───┤                     ├───┤ H │ J │ K │ L │ ; │    ' │
     * ├──────┼───┼───┼───┼───┼───┤   │                     │   ├───┼───┼───┼───┼───┼──────┤
     * │Shift │ Z │ X │ C │ V │ B │T2 │                     │T1 │ N │ M │ , │ . │ / │ Shift│
     * └──┬───┼───┼───┼───┼───┼───┴───┘ ┌───┬───┐ ┌───┬───┐ └───┴───┼───┼───┼───┼───┼───┬──┘
     *    │Ctl│GUI│Alt│ ← │ → │         │   │Ins│ │Alt│Src│         │ ↓ │ ↑ │ [ │ ] │Ctl│
     *    └───┴───┴───┴───┴───┘     ┌───┼───┼───┤ ├───┼───┼───┐     └───┴───┴───┴───┴───┘
     *                              │   │   │End│ │PgU│   │   │
     *                              │Spc│   ├───┤ ├───┤Tab│Ent│
     *                              │   │   │Hom│ │PgD│   │   │
     *                              └───┴───┴───┘ └───┴───┴───┘
     */
    [_QWERTY] = LAYOUT_ergodox_pretty(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_PPLS,            KC_PMNS,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRAVE,
        KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_EQUAL,           R_UNSCR,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    TO(_FUNC),          TO(_NUMP),  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_LEFT, KC_RIGHT,                                                  KC_DOWN, KC_UP,   KC_LBRC, KC_RBRC, KC_RCTL,
                                                     KC_NO,   KC_INS,             KC_NO,      KC_WSCH,
                                                              KC_END,             KC_PGUP,   
                                            KC_SPACE,KC_NO,   KC_HOME,            KC_PGDN,    KC_TAB,  KC_ENT
    ),
    /*
     * ┌──────┬───┬───┬───┬───┬───┬───┐                     ┌───┬───┬───┬───┬───┬───┬──────┐
     * │  Δ   │ Δ │ Δ │ Δ │ Δ │ Δ │ Δ │                     │ Δ │ θ │NmL│ / │ * │ - │   Δ  │
     * ├──────┼───┼───┼───┼───┼───┼───┤                     ├───┼───┼───┼───┼───┼───┼──────┤
     * │  Δ   │ Δ │ Δ │ Δ │ Δ │ Δ │ Δ │                     │ Δ │ θ │ 7 │ 8 │ 9 │ + │   Δ  │
     * ├──────┼───┼───┼───┼───┼───┤   │                     │   ├───┼───┼───┼───┼───┼──────┤
     * │  Δ   │ Δ │ Δ │ Δ │ Δ │ Δ ├───┤                     ├───┤ θ │ 4 │ 5 │ 6 │ = │   Δ  │
     * ├──────┼───┼───┼───┼───┼───┤   │                     │   ├───┼───┼───┼───┼───┼──────┤
     * │  Δ   │ Δ │ Δ │ Δ │ Δ │ Δ │T0 │                     │ θ │ θ │ 1 │ 2 │ 3 │Ent│   Δ  │
     * └──┬───┼───┼───┼───┼───┼───┴───┘ ┌───┬───┐ ┌───┬───┐ └───┴───┼───┼───┼───┼───┼───┬──┘
     *    │ Δ │ Δ │ Δ │ Δ │ Δ │         │   │ Δ │ │ Δ │ Δ │         │ 0 │ 0 │Del│Ent│ Δ │
     *    └───┴───┴───┴───┴───┘     ┌───┼───┼───┤ ├───┼───┼───┐     └───┴───┴───┴───┴───┘
     *                              │   │   │ Δ │ │ Δ │   │   │
     *                              │ Δ │ Δ ├───┤ ├───┤ Δ │ Δ │
     *                              │   │   │ Δ │ │ Δ │   │   │
     *                              └───┴───┴───┘ └───┴───┴───┘
     */
    [_NUMP] = LAYOUT_ergodox_pretty(   
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS,    KC_NO,   KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS,    KC_NO,   KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_NO,   KC_P4,   KC_P5,   KC_P6,   KC_EQUAL,KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(_QWERTY),        TO(_QWERTY),KC_NO,   KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                   KC_P0,   KC_P0,   KC_DEL,  KC_PENT, KC_TRNS,
                                                     KC_TRNS, KC_TRNS,            KC_TRNS,    KC_TRNS,
                                                              KC_TRNS,            KC_TRNS,   
                                            KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS,    KC_TRNS, KC_TRNS
    ),
    /*
     * ┌──────┬───┬───┬───┬───┬───┬───┐                     ┌───┬───┬───┬───┬───┬───┬──────┐
     * │  Δ   │F1 │F2 │F3 │F4 │F5 │ Δ │                     │ Δ │F6 │F7 │F8 │F9 │F10│  Δ   │
     * ├──────┼───┼───┼───┼───┼───┼───┤                     ├───┼───┼───┼───┼───┼───┼──────┤
     * │  Δ   │F11│F12│F13│F14│F15│ Δ │                     │ Δ │F16│F17│F18│F19│F20│  Δ   │
     * ├──────┼───┼───┼───┼───┼───┤   │                     │   ├───┼───┼───┼───┼───┼──────┤
     * │  Δ   │F21│F22│F23│F24│ θ ├───┤                     ├───┤ θ │ θ │ θ │ θ │ θ │  Δ   │
     * ├──────┼───┼───┼───┼───┼───┤   │                     │   ├───┼───┼───┼───┼───┼──────┤
     * │Shift │ θ │ θ │ θ │ θ │ θ │ θ │                     │T0 │ θ │ θ │ θ │ θ │ θ │ Shift│
     * └──┬───┼───┼───┼───┼───┼───┴───┘ ┌───┬───┐ ┌───┬───┐ └───┴───┼───┼───┼───┼───┼───┬──┘
     *    │Ctl│GUI│Alt│ ← │ → │         │PrS│ Δ │ │ Δ │ Δ │         │ ↓ │ ↑ │Alt│GUI│Ctl│
     *    └───┴───┴───┴───┴───┘     ┌───┼───┼───┤ ├───┼───┼───┐     └───┴───┴───┴───┴───┘
     *                              │   │   │ Δ │ │ Δ │   │   │
     *                              │ Δ │ Δ ├───┤ ├───┤ Δ │ Δ │
     *                              │   │   │ Δ │ │ Δ │   │   │
     *                              └───┴───┴───┘ └───┴───┴───┘
     */   
    [_FUNC] = LAYOUT_ergodox_pretty(   
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,            KC_TRNS,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
        KC_TRNS, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_TRNS,            KC_TRNS,    KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_TRNS,
        KC_TRNS, KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_NO,                                   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
        KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   TO(_QWERTY),        TO(_QWERTY),KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_LEFT, KC_RIGHT,                                                  KC_DOWN, KC_UP,   KC_RALT, KC_RGUI, KC_RCTL,
                                                     KC_PSCR, KC_TRNS,            KC_TRNS,    KC_TRNS,
                                                              KC_TRNS,            KC_TRNS, 
                                            KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS,    KC_TRNS, KC_TRNS
    )  
};

// Custom logic to 'paint' keyboard on layer change
// It's supper basic bec I don't write C and I'm limited on time.
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t current_layer = get_highest_layer(layer_state|default_layer_state);
    for (uint8_t i = led_min; i < led_max; i++) {
        if ((i < 37 || i > 42) && (i < 80)) {
        switch(current_layer) {
            case _FUNC:
                rgb_matrix_set_color(i, RGB_OFF);
                break;
            case _NUMP:
                 rgb_matrix_set_color(i, RGB_OFF);
                break;
            default:
                rgb_matrix_set_color(i, RGB_BLUE);
                //
                // if (i == 1) { rgb_matrix_set_color(i, RGB_AZURE);}
                // if (i == 2) { rgb_matrix_set_color(i, RGB_OFF);}
                // if (i == 3) { rgb_matrix_set_color(i, RGB_BLUE);}
                // if (i == 4) { rgb_matrix_set_color(i, RGB_CHARTREUSE);}
                // if (i == 5) { rgb_matrix_set_color(i, RGB_CORAL);}
                // if (i == 6) { rgb_matrix_set_color(i, RGB_CYAN);}
                // if (i == 7) { rgb_matrix_set_color(i, RGB_GOLD);}
                // if (i == 8) { rgb_matrix_set_color(i, RGB_GOLDENROD);}
                // if (i == 9) { rgb_matrix_set_color(i, RGB_GREEN);}
                // if (i == 10) { rgb_matrix_set_color(i, RGB_MAGENTA);}
                // if (i == 11) { rgb_matrix_set_color(i, RGB_ORANGE);}
                // if (i == 12) { rgb_matrix_set_color(i, RGB_PINK);}
                // if (i == 13) { rgb_matrix_set_color(i, RGB_PURPLE);}
                // if (i == 14) { rgb_matrix_set_color(i, RGB_RED);}
                // if (i == 15) { rgb_matrix_set_color(i, RGB_SPRINGGREEN);}
                // if (i == 16) { rgb_matrix_set_color(i, RGB_TEAL);}
                // if (i == 17) { rgb_matrix_set_color(i, RGB_TURQUOISE);}
                // if (i == 18) { rgb_matrix_set_color(i, RGB_WHITE);}
                // if (i == 18) { rgb_matrix_set_color(i, RGB_YELLOW);}
                break;
        } }
    }
    switch(current_layer) {
        case _FUNC:
            // Left
            rgb_matrix_set_color(1,RGB_RED);
            rgb_matrix_set_color(2,RGB_RED);
            rgb_matrix_set_color(3,RGB_RED);
            rgb_matrix_set_color(4,RGB_RED);
            rgb_matrix_set_color(5,RGB_RED);
            rgb_matrix_set_color(8, RGB_GREEN);
            rgb_matrix_set_color(9, RGB_GREEN);
            rgb_matrix_set_color(10, RGB_GREEN);
            rgb_matrix_set_color(11, RGB_GREEN);
            rgb_matrix_set_color(12, RGB_GREEN);
            rgb_matrix_set_color(15, RGB_BLUE);
            rgb_matrix_set_color(16, RGB_BLUE);
            rgb_matrix_set_color(17, RGB_BLUE);
            rgb_matrix_set_color(18, RGB_BLUE);
            // Right
            rgb_matrix_set_color(44,RGB_RED);
            rgb_matrix_set_color(45,RGB_RED);
            rgb_matrix_set_color(46,RGB_RED);
            rgb_matrix_set_color(47,RGB_RED);
            rgb_matrix_set_color(48,RGB_RED);
            rgb_matrix_set_color(55,RGB_GREEN);
            rgb_matrix_set_color(54,RGB_GREEN);
            rgb_matrix_set_color(53, RGB_GREEN);
            rgb_matrix_set_color(52, RGB_GREEN);
            rgb_matrix_set_color(51, RGB_GREEN);
            break;
        case _NUMP:
            // Left
            rgb_matrix_set_color(15,RGB_RED);
            rgb_matrix_set_color(16,RGB_RED);
            rgb_matrix_set_color(17,RGB_RED);
            rgb_matrix_set_color(11,RGB_RED);
            // Right
            rgb_matrix_set_color(44,RGB_BLUE);
            rgb_matrix_set_color(45,RGB_BLUE);
            rgb_matrix_set_color(46,RGB_BLUE);
            rgb_matrix_set_color(47,RGB_MAGENTA);
            rgb_matrix_set_color(55,RGB_BLUE);
            rgb_matrix_set_color(54,RGB_GREEN);
            rgb_matrix_set_color(53, RGB_GREEN);
            rgb_matrix_set_color(52, RGB_GREEN);
            rgb_matrix_set_color(58, RGB_BLUE);
            rgb_matrix_set_color(59, RGB_GREEN);
            rgb_matrix_set_color(60, RGB_GREEN);
            rgb_matrix_set_color(61, RGB_GREEN);
            rgb_matrix_set_color(68, RGB_YELLOW);
            rgb_matrix_set_color(67, RGB_GREEN);
            rgb_matrix_set_color(66, RGB_GREEN);
            rgb_matrix_set_color(65, RGB_GREEN);
            rgb_matrix_set_color(71, RGB_YELLOW);
            rgb_matrix_set_color(72, RGB_MAGENTA);
            rgb_matrix_set_color(73, RGB_GREEN);
            rgb_matrix_set_color(74, RGB_GREEN);
            break;
        default:
            // Left
            rgb_matrix_set_color(15, RGB_RED);
            rgb_matrix_set_color(16, RGB_RED);
            rgb_matrix_set_color(17, RGB_RED);
            rgb_matrix_set_color(18, RGB_RED);
            // Right
            rgb_matrix_set_color(58, RGB_GREEN);
            rgb_matrix_set_color(59, RGB_GREEN);
            rgb_matrix_set_color(60, RGB_GREEN);
            rgb_matrix_set_color(61, RGB_GREEN);
            break;
    }
    return false;
}
