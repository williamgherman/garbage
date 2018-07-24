/*
 * snek: ncurses snake game
 * William Gherman, 2018-07-24
 *
 * TODO: make movable head
 *       add collisions with wall, tail and food
 *       make food increase tailsize
 *       make food spawn in only non-tail tiles
 *       add win screen
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

#define HEIGHT 24
#define WIDTH  80

typedef struct Map {
    char tiles[WIDTH][HEIGHT];
    char tail[WIDTH][HEIGHT];
} Map;

void setup_curses();
void tidy_up();
Map *getmap();
void printmap(Map *m);
void freemap(Map *m);

int main(int argc, char **argv)
{
    int tailsize = 3;
    Map *m = getmap();
    srand(time(NULL));
    setup_curses();

    m->tiles[WIDTH/2][HEIGHT/2] = '@';
    m->tiles[rand() % WIDTH][rand() % HEIGHT] = '$';
    printmap(m);
    getch();

    tidy_up();
    freemap(m);
    return 0;
}

void setup_curses()
{
    initscr();
    raw();
    noecho();
    curs_set(0);
}

void tidy_up()
{
    endwin();
}

Map *getmap()
{
    int i, j;
    Map *m;
    if ((m = malloc(sizeof(Map))) == NULL)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < WIDTH; i++)
        for (j = 0; j < HEIGHT; j++)
            m->tiles[i][j] = ' ';
    return m;
}

void printmap(Map *m)
{
    int i, j;
    for (i = 0; i < WIDTH; i++)
    {
        for (j = 0; j < HEIGHT; j++)
            mvprintw(j, i, "%c", m->tiles[i][j]);
    }
    refresh();
}

void freemap(Map *m)
{
    free(m);
    m = NULL;
}
