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
#define MATRIX_ROW_PINS \
    { GP13, GP12, GP11, GP10, GP9 }
#define MATRIX_COL_PINS \
    { GP0, GP1, GP2, GP3, GP4, GP5, GP6, GP7, GP14, GP29, GP28, GP27, GP26, GP15, GP8 }

// Rows are doubled-up
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

#define DIODE_DIRECTION COL2ROW

