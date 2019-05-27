/*
 * Rock, Paper, Scissors
 *
 * Written by William Gherman
 * 2018-07-17
 */


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print_help()
{

    printf("Enter r, p or s to play.\n"
           "Enter ^D or q to quit.\n"
           "> ");
}

void win(char c, char d, int *score)
{
    ++*score;
    printf("%c vs %c: You win! Score: %d\n", c, d, *score);
}

void lose(char c, char d, int *score)
{
    --*score;
    printf("%c vs %c: You lose! Score: %d\n", c, d, *score);
}

void tie(char c, char d, int *score)
{
    printf("%c vs %c: You tie! Score: %d\n", c, d, *score);
}

int main()
{
    int c;
    int random;
    int score;
    int d;

    score = 0;
    srand(time(NULL));
    printf("Rock, Paper, Scissors\n"
           "---------------------\n");
    print_help();

    while ((c = getchar()) != EOF && c != 'q')
    {
        if (c != 'r' && c != 'p' && c != 's')
        {
            print_help();
            continue;
        }
        random = rand() % 3;
        d = (random == 0 ? 'r' : (random == 1 ? 'p' : 's'));
        if (c == 'r')
        {
            if (d == 'r')
                tie(c, d, &score);
            else if (d == 'p')
                lose(c, d, &score);
            else if (d == 's')
                win(c, d, &score);
        }

        else if (c == 'p')
        {
            if (d == 'r')
                win(c, d, &score);
            else if (d == 'p')
                tie(c, d, &score);
            else if (d == 's')
                lose(c, d, &score);
        }
        else if (c == 's')
        {
            if (d == 'r')
                lose(c, d, &score);
            else if (d == 'p')
                win(c, d, &score);
            else if (d == 's')
                tie(c, d, &score);
        }
    }
    printf("Final score: %d\n", score);
    return 0;
}
