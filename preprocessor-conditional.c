#include <stdio.h>

char *check(char *b) {
    return b;
}
void f() {
    char *buf = malloc(100);
    if (buf == 0) return;

    gets(buf);
#if 0
    buf = check(buf);
#endif
    puts(buf);
    free(buf);
}

// produces taint error as expected, since the sanitizer function never gets called
