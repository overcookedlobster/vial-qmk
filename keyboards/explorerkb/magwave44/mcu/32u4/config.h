/*
 * Copyright 2024 @DreaM117er
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

/* Key matrix configuration. */
#define MATRIX_ROW_PINS \
    { B1, B3, B2, B6 }
#define MATRIX_COL_PINS \
    { D4, C6, D7, E6, B4, B5 }

/* Main Keyboard Hand*/
#define USE_SERIAL
#define SERIAL_USE_MULTI_TRANSACTION
#define SOFT_SERIAL_PIN D2
#define MASTER_RIGHT

/* Encoder EC-11 */
#define ENCODERS_PAD_A { F6 }
#define ENCODERS_PAD_B { F7 }
#define ENCODERS_PAD_A_RIGHT { F6 }
#define ENCODERS_PAD_B_RIGHT { F7 }
#define ENCODER_RESOLUTION 2
#define TAP_CODE_DELAY 10
