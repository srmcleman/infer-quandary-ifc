#include <stdio.h>

char *check(char *b) {
    return b;
}

char *gets_different_kind(char *str) {
	return gets(str);
}

int *puts_different_kind(const char *str) {
	return puts(str);
}

void f() {
    char *buf = malloc(100);
    if (buf == 0) return;

	gets_different_kind(buf);
	buf = check(buf);
	puts_different_kind(buf);
	free(buf);
}

// Tests using source and sink with different "kind" attribute in .inferconfig.
// Both the source and sink were given a random string as the "kind", and this
// does not appear to affect Quandary's behaviour, i.e. these attributes appear
// to simply be labels for the convenience of the user.
