// Άσκηση 3
#include <math.h>
#include <stdio.h>

float growingTime(float growthRate, float k) {
    // Υπολογίζει πόσος χρόνος χρειάζεται (σε έτη) για έναν πληθυσμό να
    // γίνει k-πλάσιος του αρχικού με ποσοστιαίο ρυθμό αύξησης growthRate%
    return log(k) / log(1 + growthRate / 100);
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
    if (growthRate > 0)  // ο υπολογισμός έχει νόημα μόνο για θετικούς ρυθμούς μεταβολής
        printf("The population will double in %g years.\n", growingTime(growthRate, 2.0));
    else if (growthRate < 0)
        printf("The population is shrinking and will never double.\n");
    else
        printf("The population is constant and will never double.\n");

    return 0;
}
