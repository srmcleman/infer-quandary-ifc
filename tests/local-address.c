#include <stdlib.h>

int *boo(int *p, int *n, int v) {
    *p++ = v;
    *n += 1;
}

void test() {
    int *packet_data = NULL;
    int packet_data_length = 0;
    packet_data = boo(packet_data, &packet_data_length, 0);
    printf("packet_data: %d\n", packet_data);
}
