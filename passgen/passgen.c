/*
 * Passgen Password Generator
 *
 * Written by William Gherman
 * 2018-07-17
 */


#include <stdio.h>
#include <stdlib.h> /* exit */
#include <string.h> /* atoi */
#include <ctype.h>  /* isprint */
#include "sodium.h" /* randombytes_uniform */

/* Change to "./diceware.txt" for classic diceware word list */
#define WORD_LIST "./beale.txt"

int move_to_line(FILE *fp, int line)
{
    int count = 0;
    int prev = '\n';
    int c;

    rewind(fp);
    while (line > 0 && (c = fgetc(fp)) != EOF)
    {
        if (c == '\n')
            line--;
        if (prev == '\n')
            count++;
        prev = c;
    }
    return count;
}

void print_line(FILE *fp, int line)
{
    int c;
    move_to_line(fp, line);
    while ((c = fgetc(fp)) != EOF && c != '\n')
    {
        if (isprint(c))
            putchar(c);
    }
    putchar(' ');
}

int main(int argc, char **argv)
{
    FILE *fp;
    int i;
    int words;
    int lines;
    if (argc != 2)
    {
        fprintf(stderr, 
                "Usage: %s [NUMBER OF WORDS]\n"
                "       [NUMBER OF WORDS] is the number of words or phrases\n"
                "       to be selected from the Diceware Beale list. A\n"
                "       minimum of 6 is recommended.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    words = atoi(argv[1]);

    if ((fp = fopen(WORD_LIST, "r")) == NULL)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    lines = move_to_line(fp, RAND_MAX);

    for (i = 0; i < words; i++)
        print_line(fp, randombytes_uniform(lines));
    putchar('\n');
    
    fclose(fp);
    exit(EXIT_SUCCESS);
}
