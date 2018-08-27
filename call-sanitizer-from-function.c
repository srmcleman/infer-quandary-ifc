#include <stdio.h>

char *check(char *b) {
    return b;
}

char *call_sanitizer(char *b) {
    return check(b);
}

void f() {
    char *buf = malloc(100);
    if (buf == 0) return;

    gets(buf);
    buf = call_sanitizer(buf);
    puts(buf);
    free(buf);
}

// No error; this is as expected. Sanitizer is simply called from another 
// function.
