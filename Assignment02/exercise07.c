#include <stdio.h>
// Άσκηση 7

int sumOf(int N) {
    int sum = 0;
    for (int i = 0; i <= N; i++) sum += i;  // sum = 0 + 1 + … + N
    return sum;
}

void printFirst(int N) {  // Εκτυπώνει τους πρώτους Ν φυσικούς με κόμμα ενδιάμεσά τους
    for (int i = 0; i < N; i++) {
        printf("%d, ", i);
    }
    // σβήνουμε το τελευταίο κόμμα και το αντικαθιστούμε με το κενό
    printf("\b\b ");
    return;
}

void printFirstSquares(int N) {  // Εκτυπώνει τα πρώτα Ν τέλεια τετράγωνα με κόμμα ενδιάμεσά τους

    for (int i = 0; i < N; i++) {
        printf("%d, ", i * i);
    }

    // σβήνουμε το τελευταίο κόμμα και το αντικαθιστούμε με το κενό
    printf("\b\b \n");
    return;
}

float average(int sum, int count) {  // Υπολογίζει και επιστρέφει τον μέσο όρο
    return (float)sum / count;
}

int main() {
    int N;
    do {
        printf("Give an integer: ");
        scanf("%d", &N);
        // δεν μπορεί να υπάρχει μηδενικό ή αρνητικό πλήθος
        if (N <= 0) {
            printf("Cannot execute for a non-positive number.\n");
        }
    } while (N <= 0);

    printf("The first %d natural numbers are: ", N);
    printFirst(N);

    int sum = sumOf(N);
    printf("\nThe sum of them is %d", sum);

    printf("\nTheir average is %g", average(sum, N));

    printf("\nTheir squares are: ");
    printFirstSquares(N);
    return 0;
}
