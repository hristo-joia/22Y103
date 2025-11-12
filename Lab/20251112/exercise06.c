#include <stdio.h>
// Άσκηση 6

int main() {
    int n;
    printf("Give how many numbers to scan: ");
    scanf("%d", &n);

    int numbers[n];
    printf("Give %d numbers to scan:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    int maxNum = numbers[0];
    int maxCount = 0;
    int count = 1;

    for (int i = 1; i < n; i++) {
        // αν είναι ο ίδιος αριθμός
        if (numbers[i] == numbers[i - 1]) {
            count++;
        } else {
            // αν ο αριθμός είχε τις περισσότερες διαδοχικές εμφανίσεις
            if (count > maxCount) {
                maxCount = count;
                maxNum = numbers[i - 1];
            }

            // επαναφορά μετρητή
            count = 1;
        }
    }
    if (maxCount == 1)  // κανένας αριθμός δεν επανεμφανίστηκε συνεχόμενα
        printf("No number appeared more than once consecutively.\n");
    else
        printf(
            "The number %d appeared the most, with %d continuous occurances.\n",
            maxNum, maxCount);
    return 0;
}
