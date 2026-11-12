#ifndef _BOARD_
#define _BOARD_

/* Board is a singleton module containing the state of the game board
 * including the LED matrix
 *
 * The matrix is an 6 wide array of uint8_t.
 * The 4 columns of the array are represented
 * by the first 4 bits of the uint8_t
*/ 

#include "stdint.h"
 
#define MAT_SIZE 6

static struct
{
    uint8_t current_row;
    uint8_t matrix[MAT_SIZE];

} game_board;

/* Initializes game board & allocates matrix.
*/ 
void game_board_init(void);

/*
*/ 
void game_board_step(void);


#endif
