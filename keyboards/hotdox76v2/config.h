// Copyright 2021 JasonRen(biu)
// Copyright 2022 Drashna Jael're (@Drashna Jael're)
// Copyright 2024 Sebastian Echeverry (uno-sebastian)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
// #define NO_ACTION_LAYER
#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT

#define NO_AUTO_SHIFT_TAB // Do not Auto Shift KC_TAB but leave Auto Shift enabled for the other special characters.
#define NO_AUTO_SHIFT_ALPHA 

#define SPLIT_TRANSACTION_IDS_KB KEYBOARD_CURRENT_ALPA_SYNC
