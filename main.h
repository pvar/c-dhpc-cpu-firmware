/**
 * @file main.h
 * @brief Functions that perform data preprocessing and simple sanity checks,
 * insert busy-delays and print messages.

 */

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include <util/setbaud.h>
#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include <avr/interrupt.h>

#include "io.h"
#include "interpreter.h"
#include "printing.h"

// =============================================================================
// PROTOTYPES OF NON-STATIC FUNCTIONS
// =============================================================================

int main (void);

// internal data handling
void uppercase (void);
void ignorespace (void);
void push_byte (uint8_t b);
uint8_t pop_byte (void);
int16_t str_to_num (uint8_t *strptr);
uint8_t *find_line (void);
void get_line (void);

uint8_t break_test (void);

uint16_t valid_filename_char (uint8_t c);
uint8_t * valid_filename (void);

void fx_delay_ms (uint16_t ms);
void fx_delay_us (uint16_t us);

// =============================================================================
// CONSTANTS AND CUSTOM DATA TYPES
// =============================================================================

#define MAXCPL 32
#define TXT_COL_DEFAULT 76
#define TXT_COL_ERROR 3

#define cfg_auto_run 		1 // 1st bit
#define cfg_run_after_load	2 // 2nd bit
#define cfg_from_sdcard		4 // 3rd bit
#define cfg_from_eeprom 	8 // 4th bit

// =============================================================================
// GLOBAL VARIABLES
// =============================================================================

uint8_t main_config;

#endif
