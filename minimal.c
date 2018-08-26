void bad(int redact) {
    char *buf = malloc(100);
    if(buf == 0)
        return;
    gets(buf);
    redact = 1;
    if(redact) {
        free(buf);
        buf = "";
    }
    puts(buf);
    if(!redact) {
        free(buf);
    }
}


