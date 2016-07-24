/**
 * @file cmd_other.h
 * @brief Functions for program execution and other common tasks,
 * like assinging values to variables, pritining program list and so on.
 */

#ifndef CMD_OTHER_H
#define CMD_OTHER_H

#include <stdio.h>
#include <stdlib.h>
#include "interpreter.h"
#include "parser.h"

// =============================================================================
// PROTOTYPES OF NON-STATIC FUNCTIONS
// =============================================================================

int8_t prog_run (void);
int8_t prog_end (void);
int8_t prog_new (void);
int8_t input (void);
int8_t assignment (void);
int8_t poke (void);
int8_t list (void);
int8_t mem (void);
int8_t randomize (void);
int8_t rndseed (void);

#endif