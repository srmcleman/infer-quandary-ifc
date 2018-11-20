#include <stdio.h>
#include <stdlib.h>

char *check(char *b) {
    return b;
}

void f() {
    char *buf = malloc(100);
    if (buf == 0) return;

    char *single_byte;

    gets(buf);
    strncpy(single_byte, &buf[50], 1);
    buf = check(buf); 
	//single_byte = check(&single_byte);
	//note: allowing this check fixes the error as expected
    
    puts(buf); 
	puts(single_byte);

    free(buf);
}


// Quandary produces a taint error if even if a single byte from the source
// is copied and not sanitized. This is as expected: it wouldn't make sense
// to allow any part of the tainted input to make it to a sink (e.g. it
// could be an escape character that produces unintended behaviour in
// the target system).
//
// Note that it appears to make no difference which particular byte is
// copied: whether it's the first, last, or somewhere inbetween, the same
// result is produced.
