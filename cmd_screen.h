/*
 * Implementation of graphics related commands of nstBASIC.
 *
 * Copyright 2016, Panagiotis Varelas <varelaspanos@gmail.com>
 *
 * nstBASIC is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * nstBASIC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/gpl-3.0.html>.
 */

#ifndef CMD_SCREEN_H
#define CMD_SCREEN_H

#include "interpreter.h"
#include "parser.h"

uint8_t reset_display (void);
uint8_t clear_screen (void);
uint8_t pen (void);
uint8_t paper (void);
uint8_t print (void);
uint8_t locate (void);
uint8_t pset (void);

#endif
