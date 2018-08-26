#include <stdlib.h>

/* run with:
infer --quandary-only run -- clang -c test.c -o test.o
 */

/* .inferconfig
{
    "quandary-sources": [ { "procedure": "gets", "kind": "PrivateData" } ],
    "quandary-sinks":   [ { "procedure": "puts", "kind": "Logging" } ],
    "quandary-sanitizers": [ { "procedure": "check" } ]
}
 */

char redacted[] = "redacted";

char *check(char *buf) {
    return buf;
}

/* expected output:
test.c:40: error: QUANDARY_TAINT_ERROR
  Other(gets()) at line 39, column 5 ~> Other(puts()) at line 40, column 5.
 */

void *xmalloc(size_t len) {
    void *p = malloc(len);
    if(p) return p;
    else exit(1);
}

char *passthrough(char *buf, int flag) {
    if(flag)
        return redacted;
    else
        return buf;
}

void unsound() {
    char *buf = xmalloc(100);
    buf = gets(buf);
    puts(buf);
    free(buf);
}

void good() {
    char *buf = xmalloc(100);
    gets(buf);
    buf = check(buf);
    puts(buf);
    free(buf);
}

void bad() {
    char *buf = xmalloc(100);
    gets(buf);
    buf = passthrough(buf, 1);
    puts(buf);
    free(buf);
}

char *in() {
    char *buf = xmalloc(100);
    gets(buf);
    return buf;
}

void out(const char *buf) {
    puts(buf);
}

void top() {
    char *buf = in();
    out(buf);
    free(buf);
}

