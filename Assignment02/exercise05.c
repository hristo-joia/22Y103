#include <stdio.h>
//Άσκηση 5

int main() {
    int num;
    printf("Give number to check if it is prime: ");
    scanf("%d", &num);

    if (num == 1){
        printf("1 is not prime by definition.\n");
        return 0;
    }

    int divisors = 0;
    for (int i = 1; i<=num; i++){
        if (num%i == 0) divisors++;
    }

    if (divisors == 2) printf("%d is prime.\n", num, divisors);
    else printf("%d is not prime. It can be divided by %d numbers.\n", num, divisors);
    return 0;
}
