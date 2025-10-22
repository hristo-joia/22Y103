#include <stdio.h>

//Άσκηση 1

int main(){
    double a, b, c; // πραγματικές μεταβλητές για τις πλευρές του τριγώνου
    printf("Give the lengths of a three-sided triangle: ");
    scanf("%f%f%f", &a, &b, &c);

        // πρέπει να ισχύουν ταυτόχρονα οι ανισότητες
    if ((a + b > c) && (a + c > b) && (b + c > a))
        printf("This triangle exists.");
    else
        printf("Thereis no such triangle.");
    return 0;
}
