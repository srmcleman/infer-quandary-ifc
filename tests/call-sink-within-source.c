#include <stdio.h>

char *check(char *b) {
    return b;
}

int *puts_call_sink_within_source(const char *str) {
	return puts(str);
}

char *gets_call_sink_within_source(char *str) {
	str="MALICIOUS STRING";
	puts_call_sink_within_source(str);
	return str;
}

void f() {
    char *buf = malloc(100);
    if (buf == 0) return;

	gets_call_sink_within_source(buf);
	puts_call_sink_within_source(buf);
	free(buf);
}

// Quandary does not appear to identify a taint error if a sink procedure 
// (in this case 'puts_call_sink_within_source') is called and passed tainted data from *within* 
// a source procedure. 
//
// In this example, calling puts_call_sink_within_source with tainted data *after* the call to gets_call_sink_within_source
// results in a taint error as expected. However, the call to puts_call_sink_within_source from *within* 
// gets_call_sink_within_source does not produce an error, despite the fact that a user or code within 
// the procedure could inject and return a malicious string.
//
// This is somewhat unexpected and not ideal, as a developer might want to craft
// their own functions for obtaining user input and define these as sources,
// in which case Quandary would fail to identify tainted code/input reaching a sink from
// within this function itself.
