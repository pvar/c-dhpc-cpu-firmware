/**
 * @file interpreter.h
 * @brief System specifications, global variables and function prototypes.
 *
 * Most of the macros in this file play a decisive role in what this system can achieve!
 * The program memory size determines the maximum size of user programs, while the stack size
 * determines the maximum number of nested function calls.
 */

#ifndef INTERPRETER_H
#define INTERPRETER_H

// ------------------------------------------------------------------------------
// INCLUDES
// ------------------------------------------------------------------------------

#include "main.h"
#include "cmd_audio.h"
#include "cmd_screen.h"
#include "cmd_flow.h"
#include "cmd_eeprom.h"
#include "cmd_serial.h"
#include "cmd_pinctl.h"
#include "cmd_other.h"

// ------------------------------------------------------------------------------
// PROTOTYPES
// ------------------------------------------------------------------------------

uint16_t get_line_numberber (void);
void basic_init (void);
void interpreter (void);

// ------------------------------------------------------------------------------
// MACROS
// ------------------------------------------------------------------------------

/*
 * MEMORY_SIZE = PROGRAM_SPACE + VAR_SIZE + STACK_SIZE
 * 1200 is the approximate footprint of CPU stack and variables used by the firmware
 */

#define HIGHLOW_HIGH    1
#define HIGHLOW_UNKNOWN 4

#define MEMORY_SIZE (RAMEND - 1200)
#define INPUT_BUFFER_SIZE 6
#define MAX_FRAME_COUNT 5
#define STACK_SIZE (sizeof( struct stack_for_frame ) * MAX_FRAME_COUNT)
#define VAR_SIZE sizeof( int16_t )

#define STACK_GOSUB_FLAG 'G'
#define STACK_FOR_FLAG 'F'

// ------------------------------------------------------------------------------
// ENUMERATORS
// ------------------------------------------------------------------------------

enum EXECUTION_STATUS {
        POST_CMD_NOTHING = 0,
        POST_CMD_EXEC_LINE = 1,
        POST_CMD_NEXT_LINE = 2,
        POST_CMD_NEXT_STATEMENT = 3,
        POST_CMD_WARM_RESET = 4,
        POST_CMD_PROMPT = 5,
        POST_CMD_LOOP = 6
};


// ------------------------------------------------------------------------------
// DATA TYPES
// ------------------------------------------------------------------------------

typedef uint16_t LINE_NUMBER;
typedef uint8_t LINE_LENGTH;

struct stack_for_frame {
        uint8_t frame_type;
        uint8_t for_var;
        uint16_t terminal;
        uint16_t step;
        uint8_t *line_ptr;
        uint8_t *text_ptr;
};

struct stack_gosub_frame {
        uint16_t frame_type;
        uint8_t *line_ptr;
        uint8_t *text_ptr;
};

// ------------------------------------------------------------------------------
// GLOBALS
// ------------------------------------------------------------------------------

// general messages (definitions in printing.c)
extern const uint8_t msg_welcome[25];
extern const uint8_t msg_ram_bytes[11];
extern const uint8_t msg_rom_bytes[11];
extern const uint8_t msg_available[17];
extern const uint8_t msg_break[7];
extern const uint8_t msg_ok[3];

// error messages (definitions in printing.c)
extern const uint8_t err_msgxl[6];
extern const uint8_t err_msgxr[7];
extern const uint8_t err_msg01[20];
extern const uint8_t err_msg02[13];
extern const uint8_t err_msg03[15];
extern const uint8_t err_msg04[21];
extern const uint8_t err_msg05[20];
extern const uint8_t err_msg07[18];
extern const uint8_t err_msg08[21];
extern const uint8_t err_msg09[20];
extern const uint8_t err_msg0A[18];
extern const uint8_t err_msg0B[17];
extern const uint8_t err_msg0C[19];
extern const uint8_t err_msg0D[14];
extern const uint8_t err_msg0E[17];
extern const uint8_t err_msg0F[16];
extern const uint8_t err_msg10[20];
extern const uint8_t err_msg11[22];
extern const uint8_t err_msg12[23];
extern const uint8_t err_msg13[13];
extern const uint8_t err_msg14[24];
extern const uint8_t err_msg15[21];

// functions that return nothing / might print a value (definition in parser.c)
extern const uint8_t commands[218];

// functions that return a value / print nothing (definition in parser.c)
extern const uint8_t functions[27];

// relational operators (definition in parser.c)
extern const uint8_t relop_table[12];

// other keywords (definitions in parser.c)
extern const uint8_t to_tab[3];
extern const uint8_t step_tab[5];
extern const uint8_t highlow_tab[12];

/** Holds the line number of current line. */
LINE_NUMBER line_number;

/** A huge table for storing user programs. */
uint8_t program_space[MEMORY_SIZE];
/** A table for reading user input, when executing INPUT command. */
uint8_t input_buffer[INPUT_BUFFER_SIZE];

/** Pointer for accessing variables memory space. */
uint8_t *variables_ptr;
/** Pointer for accessing "internal" -- the one used by user programs. */
uint8_t *stack_ptr;
/** Pointer to current line in program memory -- the one being/to-be executed. */
uint8_t *line_ptr;
/** Pointer to character being examined or stored, when parsing or getting data. */
uint8_t *text_ptr;
/** Pointer to last character of stored program. */
uint8_t *prog_end_ptr;
/** The upper bound fof stack space. */
uint8_t *stack_limit;
/** A special number that indicates the detected error. */
uint8_t error_code;

#endif
