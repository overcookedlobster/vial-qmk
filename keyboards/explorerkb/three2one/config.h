/*
 * Copyright 2023 @DreaM117er
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 3
#define MATRIX_COLS 4

/* Key matrix configuration. */
#define MATRIX_ROW_PINS \
    { GP12, GP13, GP14 }
#define MATRIX_COL_PINS \
    { GP8, GP9, GP10, GP11 }

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5
#define DIODE_DIRECTION COL2ROW

/* Encoder EC-11 */
#define ENCODERS_PAD_A { GP0, GP2, GP4 ,GP6 }
#define ENCODERS_PAD_B { GP1, GP3, GP5 ,GP7 }
#define ENCODER_RESOLUTION 2
#define TAP_CODE_DELAY 10
