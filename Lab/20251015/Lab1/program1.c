#include <stdio.h>

int main() {
    float x, y;

    printf("Give two numbers: ");
    scanf("%f%f", &x, &y);

    printf("%.2f + %.2f = %.2f\n", x, y, x+y);

    printf("%.2f - %.2f = %.2f\n", x, y, x-y);

    printf("%.2f * %.2f = %.2f\n", x, y, x*y);

    printf("%.2f / %.2f = %.2f\n", x, y, x/y);

    return 0;
}
