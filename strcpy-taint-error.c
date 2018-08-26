#include <stdio.h>
#include <stdlib.h>

char *check(char *b) {
    return b;
}

void f() {
    char *buf = malloc(100);
    if (buf == 0) return;

    char *copied_buf = malloc(100);
    if (copied_buf == 0) {
	free(buf);
	return;
    }

    gets(buf);
    strcpy(copied_buf, buf);
    buf = check(buf);

    puts(buf);
    puts(copied_buf);

    free(buf);
    free(copied_buf);
}

// Behaves as expected -- copies of tainted source data must also
// be sanitized before reaching sinks; produces taint error
