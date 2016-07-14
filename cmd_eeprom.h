#ifndef CMD_EEPROM_H
#define CMD_EEPROM_H

#include <stdio.h>
#include <stdlib.h>
#include "interpreter.h"
#include "parser.h"

/*******************************************************************************
 ** PROTOTYPES FOR NON-STATIC FUNCTIONS
 **/

uint8_t elist (void);
uint8_t eformat (void);
uint8_t eload (void);
uint8_t esave (void);

#endif