#include <stdio.h>
#include <stdint.h>

extern int64_t max3(int64_t, int64_t, int64_t);

int main() {
    int64_t a = 10, b = 25, c = 15;
    printf("Max: %ld\n", max3(a, b, c));
    return 0;
}