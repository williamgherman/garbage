#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *fpin, *fpout;
    int c;

    if (argc != 3) {
        fprintf(stderr, "usage: %s source_file target_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fpin = fopen(argv[1], "rb")) == NULL ||
        (fpout = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "failed to open/write to file");
        exit(EXIT_FAILURE);
    }

    while ((c = fgetc(fpin)) != EOF)
        fprintf(fpout, "%c", c);

    exit(EXIT_SUCCESS);
}
