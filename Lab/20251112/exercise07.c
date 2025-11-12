#include <stdio.h>
// Άσκηση 7

int sumOf(int N) {
    int sum = 0;
    for (int i = 0; i <= N; i++) sum += i;  // sum = 0 + 1 + … + N
    return sum;
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
    for (int i = 0; i < N; i++) {
        printf("%d, ", i);
    }

    // σβήνουμε το τελευταίο κόμμα και το αντικαθιστούμε με το κενό
    printf("\b\b \n");

    int sum = sumOf(N);
    printf("The sum of them is %d\n", sum);

    printf("Their average is %g\n", (float)sum / N);

    printf("Their squares are: ");
    for (int i = 0; i < N; i++) {
        printf("%d, ", i * i);
    }

    // σβήνουμε το τελευταίο κόμμα και το αντικαθιστούμε με το κενό
    printf("\b\b \n");
    return 0;
}
