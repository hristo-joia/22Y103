#include <stdio.h>

int main() {
    double x, y;

    printf("Give two numbers: ");
    scanf("%lf%lf", &x, &y);

    printf("%.2f + %.2f = %.2f\n", x, y, x+y);

    printf("%.2f - %.2f = %.2f\n", x, y, x-y);

    printf("%.2f * %.2f = %.2f\n", x, y, x*y);

    printf("%.2f / %.2f = %.2f\n", x, y, x/y);

    return 0;
}
