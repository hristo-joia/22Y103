#include <math.h>
#include <stdio.h>
// Άσκηση 3
// https://en.wikipedia.org/wiki/Doubling_time
int main() {
    float growthRate;

    /* Ο χρόνος διπλασιασμού είναι ανεξάρτητος του αρχικού πληθυσμού,
    αλλά αφού ζητείται από την εκφώνηση μπορούμε να επανεγγράψουμε
    τη μεταβλητή growthRate. */

    // long population;
    printf("Give city population: ");
    // scanf("%ld", &population);
    scanf("%f", &growthRate);

    printf("Give annual population growth rate as a percentage: ");
    scanf("%f", &growthRate);

    float doublingTime = log(2) / log(1 + growthRate / 100);
    printf("The population will double in %g years.\n", doublingTime);

    return 0;
}
