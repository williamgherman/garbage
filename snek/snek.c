/*
 * snek: ncurses snake game
 * William Gherman, 2018-07-24
 *
 * NB: This program relies on ncurses as well as POSIX extensions to the time.h
 *     library. Some constructs also rely on c99 features, so ensure compilation
 *     standard is set to `gnu11'.
 *
 * TODO: make movable head
 *       force 80x24 bounds
 *       add collisions with wall, tail and food
 *       make food increase tailsize
 *       make food spawn in only non-tail tiles
 *       add win screen
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h> /* uses POSIX extensions */
#include <ncurses.h>
#include <unistd.h> /* POSIX only */


#define HEIGHT 24
#define WIDTH  80

typedef enum direction{Up, Down, Left, Right} direction;

typedef struct Map {
    char tiles[WIDTH][HEIGHT];
    char tail[WIDTH][HEIGHT];
} Map;

typedef struct Snake {
    int x;
    int y;
    int tailsize;
    direction snake_direction
} Snake;

void setup_curses();
void tidy_up();
Map *initmap();
Snake *initsnake();
void printmap(Map *m);
void freemap(Map *m);
void freesnake(Snake *s);
void set_direction(Snake *s, int c);
void move_snake(Map *m, Snake *s);

int main(int argc, char **argv)
{
    int c;
    Map *m = initmap();
    Snake *s = initsnake();
    srand(time(NULL));
    setup_curses();
    

    for (int i = 0; i < s->tailsize; i++)
    {
        m->tiles[s->x + i][s->y] = '#';
        m->tail[s->x + i][s->y] = s->tailsize - i;
    }
    m->tiles[rand() % WIDTH - 1][rand() % HEIGHT - 1] = '@';
    printmap(m);

    while (1)
    {
        timeout(70);
        c = getch();
        set_direction(s, c);
        move_snake(m, s);
    }



    tidy_up();
    freemap(m);
    freesnake(s);
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

Map *initmap()
{
    Map *m;
    if ((m = malloc(sizeof(Map))) == NULL)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            m->tiles[i][j] = ' ';
            m->tail[i][j] = 0;
        }
    }
     
    for (int i = 0; i < WIDTH; i++)
        for (int j = 0; j < HEIGHT; j++)
            if (j == 0 || j == HEIGHT - 1 || (i == 0 || i == WIDTH - 1))
                m->tiles[i][j] = '*';
    return m;
}

Snake *initsnake()
{
    Snake *s;
    if ((s = malloc(sizeof(Snake))) == NULL)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    s->x = WIDTH/2;
    s->y = HEIGHT/2;
    s->tailsize = 3;
    s->snake_direction = Left;

    return s;
}

void freesnake(Snake *s)
{
    free(s);
    s = NULL;
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

void set_direction(Snake *s, int c)
{
    switch(c) {
        case 'W': case KEY_UP:
            s->snake_direction = Up;
            break;
        case 'A': case KEY_LEFT:
            s->snake_direction = Left;
            break;
        case 'S': case KEY_DOWN:
            s->snake_direction = Down; 
            break;
        case 'D': case KEY_RIGHT:
            s->snake_direction = Right;
            break;
        default:
            break;
    }
}

void move_snake(Map *m, Snake *s, direction snake_direction)
{
    switch(snake_direction) {
        case Up:
            s->snake_y--;
            break;
        case Down:
            s->snake_y++;
            break;
        case Left:
            s->snake_x--;
            break;
        case Right:
            s->snake_x++;
