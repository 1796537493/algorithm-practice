#include <stdio.h>
#include <string.h>
#include <stdint.h>

void show(float f) {
    uint32_t u;
    memcpy(&u, &f, 4);
    int s = (u >> 31) & 1;
    int e = (u >> 23) & 0xFF;
    uint32_t m = u & 0x7FFFFF;
    printf("%g = S=%d E=%d(0x%02X) M=0x%06X\n", f, s, e, e, m);
    if (e != 0 && e != 255) {
        printf("   value = %s1.%03X... * 2^(%d)\n", s ? "-" : "", m, e - 127);
    }
}

int main(void) {
    for (float v = 0; v < 10; v += 0.1f) {}
    show(6.25f);
    show(-6.25f);
    show(1.0f);
    show(0.5f);
    show(1.0f / 3.0f);

    // special values
    float z = 0.0f, n = -1.0f;
    show(z);
    show(1.0f / z);      // +inf
    show(n / z);         // -inf
    show(z / z);         // nan

    // the classic pitfall
    float a = 0.1f, b = 0.2f, c = 0.3f;
    printf("\n0.1f = %.10f\n", a);
    printf("0.2f = %.10f\n", b);
    printf("0.3f = %.10f\n", c);
    printf("(0.1+0.2) == 0.3 ? %s\n", (a + b == c) ? "true" : "false");
    printf("0.1+0.2 = %.10f\n", a + b);
    return 0;
}
