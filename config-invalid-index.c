#include <stdio.h>

char *check(char *b) {
    return b;
}

char *gets_invalid_index(char *str) {
	return gets(str);
}

int *puts_invalid_index(const char *str) {
	return puts(str);
}

void f() {
    char *buf = malloc(100);
    if (buf == 0) return;

	gets_invalid_index(buf);
	buf = check(buf);
	puts_invalid_index(buf);
	free(buf);
}

// Tests setting the "index" attribute for a source in .inferconfig to 1 (i.e.
// the second formal paramter), even though the specified procedure only has one
// formal parameter. This results in an internal error, which is probably
// what you'd expect:
//
// F....Uncaught Internal Error: (Invalid_argument "List.nth_exn 1 called on list of length 1")
//
