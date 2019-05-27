/* fizz - Modular FizzBuzz
 *
 * Written by William Gherman
 * 2018-03-26
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(int argc, char **argv) {
    int i, n;
    bool buzzed = false;
    if (argc < 3 || argc % 2 == 2) {
        fprintf(stderr, "Usage: %s maxCount word1 num1 word2 num2 ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    for (i = 1; i <= atoi(argv[1]); i++) {
        for (n = 3; n < argc; n += 2) {
            if (i % atoi(argv[n]) == 0) {
                printf("%s", argv[n-1]);
                buzzed = true;
            }
        }
        if (!buzzed)
            printf("%d", i);
        buzzed = false;
        printf("\n");
    }
    exit(EXIT_SUCCESS);
}
