#include <stdio.h>

char *check(char *b) {
    return b;
}

int *puts_second_index_source(const char *str) {
	return puts(str);
}

char *gets_second_index_source(char *str, char *second) {
	puts_second_index_source(str);
	return gets(second);
}

void f() {
    char *buf = malloc(100);
    if (buf == 0) return;

	gets_second_index_source("dummystring", buf);
	//buf = check(buf);
	puts_second_index_source(buf);
	free(buf);
}

// Tests setting the "index" attribute for a source in .inferconfig to 1 (i.e.
// the second formal paramter). Appears to behave as expected, e.g. Quandary
// identifies a taint error when data associated with the second parameter
// reaches the sink without being sanitized, whereas the first parameter
// can reach the sink without being sanitized without complaint.
