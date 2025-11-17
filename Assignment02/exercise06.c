// Άσκηση 6
#include <stdio.h>

int main() {
    int n;
    printf("Give how many numbers to scan (>1): ");
    do
        scanf("%d", &n);
    while (n <= 1);  // δεν υπάρχει αρνητική ή μοναδιαία ακολουθία

    int prevNum;
    int currNum;

    int maxNum = prevNum;
    int maxStreak = 0;
    int streak = 1;
    printf("Give %d numbers separated by a new line.\n");
    scanf("%d", &prevNum);

    for (int i = 1; i < n; i++) {  // ο πρώτος αριθμός διαβάστηκε ήδη
        scanf("%d", &currNum);
        if (prevNum == currNum) {
            // αν είναι ο ίδιος αριθμός
            streak++;
            if (streak > maxStreak) {
                // αν ο αριθμός είχε τη μεγαλύτερη ακολουθία
                maxStreak = streak;
                maxNum = prevNum;
            }
        } else {
            // αποθήκευση ακολουθίας
            // επαναφορά μετρητή
            streak = 1;
        }
        prevNum = currNum;
    }

    if (maxStreak == 1)  // κανένας αριθμός δεν επανεμφανίστηκε συνεχόμενα
        printf("No number appeared more than once consecutively.\n");
    else
        printf("The number %d appeared the most, with %d continuous occurances.\n", maxNum, maxStreak);
    return 0;
}
