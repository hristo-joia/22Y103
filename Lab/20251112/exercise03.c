#include <math.h>
#include <stdio.h>
// Άσκηση 3

float growingTime(float growthRate, float n){
    // Υπολογίζει πόσος χρόνος χρειάζεται (σε έτη) για έναν πληθυσμό να
    // γίνει n-πλάσιος του αρχικού με ποσοστιαίο ρυθμό αύξησης growthRate%
    return log(n)/log(1+growthRate/100);
}

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

    printf("The population will double in %g years.\n", growingTime(growthRate, 2.0));

    return 0;
}
