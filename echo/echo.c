#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ECHO_VERSION "Echo version 0.0.1, 2018-05-17\n"

void print_help(const char *program_name);
void print_version();
void echo(const char *s, int escape_flag);

int main(int argc, char **argv)
{
    int i;
    int escape_flag = 0; /* enable escape sequences */
    if (argc < 2)
    {
        echo("", escape_flag);
        return 0;
    }
    for (i = 1; i < argc; i++)
    {
        if (i == 1)
        {
            if (argc == 2 && !strcmp(argv[i], "--help"))
                print_help(argv[0]);
            else if (argc == 2 && !strcmp(argv[i], "--version"))
                print_version();
            else if (!strcmp(argv[i], "-e"))
            {
                escape_flag = 1;
                i++;
            }

        }
        echo(argv[i], escape_flag);
        if (i+1 < argc)
            putchar(' ');
    }
    putchar('\n');
    return 0;
}

void print_help(const char *program_name)
{
    fprintf(stderr,
            "Usage: %s [SHORT-OPTION] [STRING]...\n"
            "   or: %s LONG-OPTION\n"
            "Echoes the STRING(s) to stdout.\n"
            "\n"
            "  -e             enable backslash escapes\n"
            "  -E             disable backslash escapes (default)\n"
            "      --help     display this help and exit\n"
            "      --version  output version information and exit\n"
            "\n"
            "If -e is in effect, the following sequences are recognised:\n"
            "\n"
            "  \\\\      backslash\n"
            "  \\a      alert (BEL)\n"
            "  \\b      backspace\n"
            "  \\c      produce no further output\n"
            "  \\e      escape\n"
            "  \\f      form feed\n"
            "  \\n      new line\n"
            "  \\r      carriage return\n"
            "  \\t      horizontal tab\n"
            "  \\v      vertical tab\n",
            program_name, program_name);
    exit(EXIT_SUCCESS);
}

void print_version()
{
    fprintf(stderr, ECHO_VERSION);
    exit(EXIT_SUCCESS);
}

void echo(const char *s, int escape_flag)
{
    if (escape_flag)
    {
        while (*s)
        {
            if (*s == '\\' && *(s+1))
            {
                switch(*(s+1)) {
                    case '\\': putchar('\\');
                               break;
                    case 'a':  putchar('\a');
                               break;
                    case 'b':  putchar('\b');
                               break;
                    case 'c':  exit(EXIT_SUCCESS);
                               break;
                    case 'e':  putchar('\x1B');
                               break;
                    case 'f':  putchar('\f');
                               break;
                    case 'n':  putchar('\n');
                               break;
                    case 'r':  putchar('\r');
                               break;
                    case 't':  putchar('\t');
                               break;
                    case 'v':  putchar('\v');
                               break;
                    default:   putchar('\\');
                               s--;
                               break;
                }
                s++;
            } else {
                putchar(*s);
            }
            s++;
        }
    } else {
        while (*s)
            putchar(*s++);
    }
}
