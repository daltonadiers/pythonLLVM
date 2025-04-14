#include <stdio.h>
#include <stdint.h>

extern "C" int64_t max3(int64_t a, int64_t b, int64_t c);

int main() {
    int64_t a = 10, b = 25, c = 15;
    printf("Max: %ld\n", max3(a, b, c));
    return 0;
}