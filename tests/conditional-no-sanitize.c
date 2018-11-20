#include <stdio.h>

char *check(char *b) {
    return b;
}

void f() {
    char *buf = malloc(100);
    if (buf == 0) return;

    gets(buf);
    if (0) {
	buf = check(buf);
    }
    puts(buf);
    free(buf);
}


// would expect this to produce a taint error, since the sanitizer function never gets executed, but this isn't the case
