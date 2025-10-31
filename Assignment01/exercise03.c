#include <stdio.h>

// Άσκηση 3

int main() {
    long small, large;  // ακέραια πλήθη μπουκαλιών
    double total;       // η τιμή είναι πραγματικός

    do {
        printf("Input number of small bottles to order: ");
        scanf("%d", &small);
    } while (small < 0);

    do {
        printf("Input number of large bottles to order: ");
        scanf("%d", &large);
    } while (large < 0);
    // τα μικρά μπουκάλια κοστίζουν 0.008€ και
    // τα μεγάλα μπουκάλια κοστίζουν 0.02€
    total = small * 0.008 + large * 0.02;  // υπολογισμός μερικού συνόλου

    // υπολογισμός έκπτωσης
    // το κατώφλι των 600€ περιέχει και το κατώφλι των 200€, άρα ελέγχεται πρώτο
    if (total > 600.00)  // 20% έκπτωση για 600€ και άνω
        // 20% έκπτωση -> η τελική τιμή είναι το 80% της αρχικής
        total *= 0.8;

    // 8% έκπτωση για 200€ και άνω ή 3000 τμχ. και άνω
    else if (total > 200.00 || (small + large) > 3000)
        total *= 0.92;  // 8% έκπτωση -> 92% της αρχικής

    printf("Total cost: %.2f EUR\n", total);
    // εκτύπωση τελικής τιμής με 2 δεκαδικά

    return 0;
}
