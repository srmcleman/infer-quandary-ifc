// hello.c
#include <stdlib.h>


int test(int *a, unsigned n) {
    unsigned i;
    int sum=0;

    for(i=0;i<n;i++) {
        sum += a[i];
    }

    return sum;
}

struct foo {
    int a, b;
};

void baz(struct foo *f) {
    f->a = f->b;
}

struct list {
    void *data;
    struct list *next;
};

void append(struct list *a, struct list *b) {
    while(a->next) a = a->next;
    a->next = b;
}
