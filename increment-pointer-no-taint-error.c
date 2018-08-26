#include <stdio.h>
#include <stdlib.h>

char *check(char *b) {
    return b;
}

void f() {
    char *buf = malloc(100);
    if(buf == 0) return;

    gets(buf);
    buf += 99;
    buf = check(buf);
    buf -= 99;
    puts(buf);
    free(buf);
}

// just for testing -- program will output same string as input
int main(int argc, char **argv) {
    f();
    return 0;
}

// The pointer 'buf' is incremented by 99 before calling the 'check' function,
// which means only the last byte is sanitized. After the call to 'check',
// the pointer is decremented by 99 so that it points to the start of the
// the buffer and the calls to 'puts' and 'free' succeed.
//
// Quandary does not find any issues with this code. It probably should, 
// because only sanitizing the last byte of a source buffer before passing the
// (majority still tainted) data to a sink doesn't give us much of a security 
// guarantee.
