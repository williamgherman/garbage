/*
 * getsize - Gets size of terminal or terminal emulator window
 *
 * Written by William Gherman
 * 2018-07-17
 */

#include <curses.h>
#include <stdio.h>

int main()
{
    int x,y;
    initscr();
    x = COLS;
    y = LINES;
    endwin();
    printf("Cols: %d\nLines: %d\n", x, y);
    return 0;
}
