#include <stdio.h>

// Άσκηση 1

int main() {
    // Ο τύπος μεταβλητών για τα μήκη των πλευρών του τριγώνου πρέπει να είναι
    // πραγματικός, ώστε να ελέγχει τρίγωνα οποιουδήποτε μεγέθους
    double a, b, c;
    do {
        printf("Give the lengths of the triangle sides: ");
        scanf("%lf%lf%lf", &a, &b, &c);
        // τα μήκη των πλευρών πρέπει να είναι θετικά
    } while (a <= 0 || b <= 0 || c <= 0);

    // σύμφωνα με την εκφώνηση, πρέπει να ισχύουν ταυτόχρονα οι ανισότητες
    if ((a + b > c) && (a + c > b) && (b + c > a))
        printf("This triangle exists.\n");
    else
        printf("There is no such triangle.\n");
    return 0;
}
