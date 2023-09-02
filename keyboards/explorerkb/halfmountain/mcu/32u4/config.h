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
    { B1, B3, B2, B6 }
#define MATRIX_COL_PINS \
    { F7, F6, F5, F4, D3, D1 }
#define MATRIX_COL_PINS_RIGHT  \
    { D4, C6, D7, E6, B4, B5 }

#define SOFT_SERIAL_PIN D2

#define MASTER_LEFT
