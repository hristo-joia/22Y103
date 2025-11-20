// Άσκηση 6
#include <stdio.h>
void updateMax(int num, int* maxNum, int streak, int* maxStreak) {
    *maxStreak = streak;
    *maxNum = num;
    return;
}

void scanNums(int* maxNum, int* maxStreak) {
    // ανάγνωση αριθμών με πλήθος εισαγόμενο από τον χρήστη
    printf("Give how many numbers to scan (>1): ");
    int n;
    do
        scanf("%d", &n);
    while (n <= 1);  // δεν υπάρχει αρνητική ή μοναδιαία ακολουθία

    int prevNum;
    int currNum;
    int streak = 1;  // οι τρέχουσες διαδοχικές εμφανίσεις

    printf("Give %d numbers separated by a new line or a space.\n");
    scanf("%d", &prevNum);

    for (int i = 1; i < n; i++) {  // ο πρώτος αριθμός διαβάστηκε ήδη
        scanf("%d", &currNum);
        if (prevNum == currNum) {
            // αν είναι ο ίδιος αριθμός
            streak++;
            // αν ο αριθμός είχε τη μεγαλύτερη ακολουθία
            if (streak > *maxStreak) {
                // αποθήκευση ακολουθίας
                updateMax(currNum, maxNum, streak, maxStreak);
            }
        } else {
            // επαναφορά μετρητή
            streak = 1;
        }
        prevNum = currNum;
    }

    return;
}

void scanNumsGuard(int* maxNum, int* maxStreak);  // εναλλαγκτική υλοποίηση με χρήση τιμής φρουρού

int main() {
    int maxNum;         // ο αριθμός με τις περισσότερες διαδοχικές εμφανίσεις
    int maxStreak = 1;  // το μέγιστο πλήθος διαδοχικών εμφανίσεων

    scanNums(&maxNum, &maxStreak);
    // scanNumsGuard(&maxNum, &maxStreak); // εναλλακτικά χωρίς να χρειάζεται το μέγεθος της ακολουθίας

    if (maxStreak == 1)  // κανένας αριθμός δεν επανεμφανίστηκε συνεχόμενα
        printf("No number appeared more than once consecutively.\n");
    else
        printf("The number %d had the longest consecutive occurrances,\nwith %d consecutive occurances.\n", maxNum, maxStreak);
    return 0;
}

void scanNumsGuard(int* maxNum, int* maxStreak) {
    // μία εναλλακτική υλοποίηση που να μη χρειάζεται την εισαγωγή του πλήθους από τον χρήστη
    int prevNum;
    int currNum;
    printf("Give numbers to scan separated by a new line or a space.\nEnter 'stop' to stop.\n");
    // στην πραγματικότητα θα τερματίσει για οποιονδήποτε μη-αριθμητικό χαρακτήρα
    scanf("%d", &prevNum);

    int streak = 1;  // οι τρέχουσες διαδοχικές εμφανίσεις
    int stop = 0;
    while (stop == 0) {
        // αν ο χρήστης εισάγει χαρακτήρα που δεν είναι ψηφίο,
        // τότε η scanf θα επιστρέψει 0
        int scanSuccess = scanf("%d", &currNum);

        if ((prevNum == currNum) && (scanSuccess == 1))
            // αν είναι ο ίδιος αριθμός
            streak++;

        // αποθήκευση ακολουθίας
        if (streak > *maxStreak) {
            // αν ο αριθμός είχε τη μεγαλύτερη ακολουθία
            *maxStreak = streak;
            *maxNum = prevNum;
        } else {
            // επαναφορά μετρητή
            streak = 1;
        }
        prevNum = currNum;

        if (scanSuccess == 0) stop = 1;  // αν ο χρήστης δεν εισήγαγε ψηφίο, τερμάτισε
    }
    return;
}