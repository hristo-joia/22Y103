#include <stdio.h>
// Άσκηση 6

int main() {
    int prevNum;
    int currNum;
    printf("Give numbers to scan. Enter 'stop' to stop.\n");
    scanf("%d", &prevNum);

    int maxNum = prevNum;
    int maxStreak = 0;
    int streak = 1;

    int stop = 0;
    while (stop == 0) {
        // Αν ο χρήστης εισάγει χαρακτήρα που δεν είναι ψηφίο,
        // τότε η scanf θα επιστρέψει 0
        int scanSuccess = scanf("%d", &currNum);

        if ((prevNum == currNum) && (scanSuccess == 1))
            // αν είναι ο ίδιος αριθμός
            streak++;
        else {
            // αποθήκευση ακολουθίας
            if (streak > maxStreak) {
                // αν ο αριθμός είχε τη μεγαλύτερη ακολουθία
                maxStreak = streak;
                maxNum = prevNum;
            }
            // επαναφορά μετρητή
            streak = 1;
        }
        prevNum = currNum;

        if (scanSuccess == 0)
            stop = 1;  // αν ο χρήστης δεν εισήγαγε ψηφίο, τερμάτισε
    }

    if (maxStreak == 1)  // κανένας αριθμός δεν επανεμφανίστηκε συνεχόμενα
        printf("No number appeared more than once consecutively.\n");
    else
        printf(
            "The number %d appeared the most, with %d continuous occurances.\n",
            maxNum, maxStreak);
    return 0;
}
