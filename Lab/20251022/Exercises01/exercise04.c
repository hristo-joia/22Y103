#include <stdio.h>

//Άσκηση 4

int main(){
    int number; // ο δωσμένος αριθμός
    do {
        printf("Give a 5-digit number: ");
        scanf("%d", &number);
    } while (number<10000 || number > 100000); // ο αριθμός πρέπει να είναι πενταψήφιος


    int flipped = 0; // ο ανεστραμμένος αριθμός

    for (int i = 0; i < 5; i++) {
        flipped *= 10; // δεκαδική ολίσθιση προς τα αριστερά

        flipped += number % 10; // πρόσθεση του τελευταίου ψηφίου
        number /= 10; // δεκαδική ολίσθιση προς τα δεξιά
    }

    printf("The reversed number is %d", flipped);


    return 0;
}
