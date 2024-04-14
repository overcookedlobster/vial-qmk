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

#include "quantum.h"

// clang-format off
#define LAYOUT(                                                                        \
  K01,  K04,  K08,  K12,  K15,  K19,  K23,  K27,  K31,  K35,  K39,  K42,  K46,  K50,   \
  K02,  K05,  K09,  K13,  K16,  K20,  K24,  K28,  K32,  K36,  K40,  K43,  K47,  K51,   \
  K03,  K06,  K10,  K14,  K17,  K21,  K25,  K29,  K33,  K37,  K41,  K44,  K48,  K52,   \
        K07,  K11,        K18,  K22,  K26,  K30,  K34,  K38,        K45,  K49          \
)                                                                                      \
{                                                                                      \
{ K01,   K04,   K08,   K12,   K15,   K19,   K23   }, \
{ K02,   K05,   K09,   K13,   K16,   K20,   K24   }, \
{ K03,   K06,   K10,   K14,   K17,   K21,   K25   }, \
{ KC_NO, K07,   K11,   KC_NO, K18,   K22,   K26   }, \
{ K50,   K46,   K42,   K39,   K35,   K31,   K27   }, \
{ K51,   K47,   K43,   K40,   K36,   K32,   K28   }, \
{ K52,   K48,   K44,   K41,   K37,   K33,   K29   }, \
{ KC_NO, K49,   K45,   KC_NO, K38,   K34,   K30   }, \
}
// clang-format on
