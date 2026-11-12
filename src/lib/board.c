#include "board.h"


void game_board_init(void)
{
    // reset state of LED matrix is all off
    for (int i = 0; i < MAT_SIZE; i++) game_board.matrix[i] = 0;
    game_board.current_row = 0;
}
