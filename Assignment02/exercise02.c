#include <stdio.h>
// Άσκηση 2

int main() {
    // char character;
    for (int i = 48; i <= 126; i++) {
        // το %c εκτυπώνει τον χαρακτήρα,
        // ενώ το %d εκτυπώνει τον δεκαδικό κωδικό του
        printf("%c (%d)\t", i, i);
        if ((i - 47) % 10 == 0) printf("\n");
    }
    printf("\n");
    return 0;
}
