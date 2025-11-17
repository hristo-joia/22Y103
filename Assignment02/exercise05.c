// Άσκηση 5
#include <stdbool.h>
#include <stdio.h>

int countDivisors(int n) {
    /* Αυτή η συνάρτηση μετράει και επιστρέφει
    τους διαιρέτες ενός θετικού ακεραίου */
    int divisors = 0;
    for (int i = 1; i <= n; i++)
        if (n % i == 0) divisors++;
    return divisors;
}

bool isPrime(int n) {
    if (n < 1) return false;
    if (n == 1) {
        return false;  // ο 1 δεν είναι πρώτος
    } else {
        /* Aν ο αριθμός n δεν είναι πρώτος, από θεώρημα
        ισχύει ότι έχει τουλάχιστον έναν παράγοντα i
        μικρότερο ή ίσο του √n, δηλαδή i² ≤ n */
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0)
                return false;  // αν βρεθεί ένας παράγοντας i ≤ √n δε χρειάζεται να ελέγξουμε για άλλους

        return true;  // αν δε βρεθεί τέτοιος παράγοντας, τότε ο αριθμός είναι πρώτος
    }
}

int main() {
    int num;
    do {
        // μόνο οι φυσικοί μπορούν να είναι πρώτοι
        printf("Give a positive integer to check if it is prime: ");
        scanf("%d", &num);
    } while (num <= 0);  // επικύρωση εισόδου

    if (num == 1) {
        printf("1 is not prime by definition.\n");
        return 0;
    }

    if (isPrime(num)) {
        printf("%d is prime.\n", num);
    } else
        printf("%d is not prime. It can be divided by %d numbers.\n", num, countDivisors(num));

    return 0;
}