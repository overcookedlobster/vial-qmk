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

/* Key matrix configuration. */
#define MATRIX_ROW_PINS \
    { GP28, GP27, GP26, GP22, GP20 }
#define MATRIX_COL_PINS \
    { GP9, GP8, GP7, GP6, GP5, GP4, GP3, GP2, GP1, GP0, GP12, GP13, GP14, GP15, GP16 }

/* Encoder EC-11 */
#define ENCODERS_PAD_A { GP23 }
#define ENCODERS_PAD_B { GP21 }
#define ENCODER_RESOLUTION 2
#define TAP_CODE_DELAY 10


