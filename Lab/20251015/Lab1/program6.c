#include <stdio.h>

int main() {
    double C, F;
    printf("Give temperature in degrees Fahrenheit: ");
    scanf("%lf", &F);

    C = (F-32) * (5.0/9);

    printf("%.2f degrees Fahrenheit is %.2f degrees Celsius", F, C);
    return 0;
}
