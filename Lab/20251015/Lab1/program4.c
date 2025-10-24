#include <stdio.h>

int main() {
    int num1, num2, tmp;
    printf("Give two numbers: ");
    scanf("%d%d", &num1, &num2);
    printf("The values given are: %d and %d\n", num1, num2);

    tmp = num1;
    num1 = num2;
    num2 = tmp;

    printf("The changed values are: %d and %d\n", num1, num2);
    return 0;
}
