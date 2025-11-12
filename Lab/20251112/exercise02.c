#include <stdio.h>
// Άσκηση 2

void asciiCode2Char (char code){
    // Εκτύπωσε τον χαρακτήρα με κωδικό ASCII «code»
    printf("%c", code); // το %c εκτυπώνει τον χαρακτήρα
    return;
}

int main() {
    // char character;
    for (int i = 48; i <= 126; i++) {
        asciiCode2Char(i); // εμφάνισε τον χαρακτήρα με κωδικό «i»
        printf(" (%d)\t", i); // εκτύπωσε τον δεκαδικό κωδικό του χαρακτήρα και έναν στηλοθέτη
        if ((i - 47) % 10 == 0) printf("\n");
    }
    printf("\n");
    return 0;
}
