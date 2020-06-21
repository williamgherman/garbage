#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE *fpin, *fpout;
    int c;

    if (argc != 3) {
        fprintf(stderr, "usage: %s source_file target_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], argv[2]) == 0) {
        fprintf(stderr, "Error: source file and target file must not be the "
                        "same.\n");
        exit(EXIT_FAILURE);
    }

    if ((fpin = fopen(argv[1], "rb")) == NULL ||
        (fpout = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "failed to open/write to file");
        exit(EXIT_FAILURE);
    }

    while ((c = fgetc(fpin)) != EOF)
        fprintf(fpout, "%c", c);
    fclose(fpin);
    fclose(fpout);

    exit(EXIT_SUCCESS);
}
