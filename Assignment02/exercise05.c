#include <stdio.h>
// Άσκηση 5

int main() {
    int num;
    do {
        // μόνο οι φυσικοί μπορούν να είναι πρώτοι
        printf("Give a natural number to check if it is prime: ");
        scanf("%d", &num);
    } while (num <= 0);  // επικύρωση εισόδου

    if (num == 1) {
        printf("1 is not prime by definition.\n");
        return 0;
    }

    int divisors = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) divisors++;
    }
    // οι πρώτοι διαιρούνται μόνο από το 1 και τον εαυτό τους
    if (divisors == 2)
        printf("%d is prime.\n", num, divisors);
    else
        printf("%d is not prime. It can be divided by %d numbers.\n", num,
               divisors);
    return 0;
}
