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
    strcpy(copied_buf, buf);  // stores copy of tainted data
    buf = check(buf);  // sanitize the tainted data in buf
    strcpy(buf, copied_buf);  // copy original tainted data back into buf	
    
    puts(buf);  // output tainted data to sink

    free(buf);
    free(copied_buf);
}

// Quandary doesn't produce a taint error here, but it probably should.
// Although the tainted data in 'buf' is sanitized, we then overwrite
// it with a copy of the original unsanitized data which is stored in 
// 'copied_buf'.
