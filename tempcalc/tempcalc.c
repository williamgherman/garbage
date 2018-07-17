#include <stdio.h>
#include <stdlib.h> /* exit */
#include <string.h>

#define VERSION "0.1"

/*
 * TODO: fix input errors
 *       clean up code
 *       make c89 compatible
 */

void print_version(char *s)
{
    fprintf(stderr,
            "%s temperature converter version %s\n"
            "\n"
            "Written by William Gherman\n",
            s, VERSION);
}

void print_help(char *s)
{
    fprintf(stderr,
            "Usage:\n" 
            "  %s [OPTION] [VALUE]\n"
            "  This program accepts exactly one option at a time only and\n"
            "    accepts exactly one value only if conversion options are\n"
            "    used.\n"
            "  Values must be integer or decimal values.\n"
            "\n"
            "Options:\n"
            "  -cf  Converts from degrees Celsius to degrees Fahrenheit\n"
            "  -ck  Converts from degrees Celsius to Kelvin\n"
            "  -fc  Converts from degrees Fahrenheit to degrees Celsius\n"
            "  -fk  Converts from degrees Fahrenheit to Kelvin\n"
            "  -kc  Converts from Kelvin to degrees Celsius\n"
            "  -kf  Converts from Kelvin to degrees Fahrenheit\n" 
            "  -h   Prints this help message\n"
            "  -v   Prints version number\n"
            "\n",
            s);
}

int main(int argc, char **argv)
{
    char *p;
    double temp;
    if (argc < 2 || argc > 3 || 
        (argc == 2 && ((strcmp(argv[1], "-h")) &&
                      (strcmp(argv[1], "-v")))) || 
        (argc == 3 && (strcmp(argv[1], "-cf") && strcmp(argv[1], "-ck") &&
                       strcmp(argv[1], "-fc") && strcmp(argv[1], "-fk") &&
                       strcmp(argv[1], "-kc") && strcmp(argv[1], "-kf"))))
    {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "-h") == 0)
    {
        print_help(argv[0]);
        exit(EXIT_SUCCESS);
    }
    if (strcmp(argv[1], "-v") == 0)
    {
        print_version(argv[0]);
        exit(EXIT_SUCCESS);
    }
    temp = strtod(argv[2], &p);
    if (*p != '\0')
    {
        fprintf(stderr,
                "Error: temperature value must be an integer or decimal.\n");
        exit(EXIT_FAILURE);
    }
    if (!strcmp(argv[1], "-cf"))
        printf("%g degrees C = %g degrees F\n", temp, temp * 9 / 5 + 32);
    if (!strcmp(argv[1], "-ck"))
        printf("%g degrees C = %g K\n", temp, temp + 273.15);
    if (!strcmp(argv[1], "-fc"))
        printf("%g degrees F = %g degrees C\n", temp, (temp - 32) / 9 * 5);
    if (!strcmp(argv[1], "-fk"))
        printf("%g degrees F = %g K\n", temp, (temp + 459.67) / 9 * 5);
    if (!strcmp(argv[1], "-kc"))
        printf("%g K = %g degrees C\n", temp, temp - 273.15);
    if (!strcmp(argv[1], "-kf"))
        printf("%f K = %f degrees F\n", temp, temp * 9 / 5 + 459.67);
    exit(EXIT_SUCCESS);
}
