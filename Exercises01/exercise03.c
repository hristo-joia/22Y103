#include <stdio.h>

//Άσκηση 3

int main(){
    long small, large; // ακέραιες τιμές μπουκαλιών
    double total; // πραγματική τιμή τιμής

    printf("Input number of small bottles to order: ");
    scanf("%d", &small);

    printf("Input number of large bottles to order: ");
    scanf("%d", &large);

    total = small * 0.008 + large * 0.02; // υπολογισμός μερικού συνόλου

    // υπολογισμός έκπτωσης
    if (total > 600.00) // έκπτωση για 600€ και άνω
        total = total * 0.8; // 20% έκπτωση -> η τελική τιμή είναι το 80% της αρχικής
    else if (total > 300.00 || (small + large) > 3000) // έκπτωση για 300€ και άνω ή 3000 τμχ. και άνω
        total = total * 0.92; // 8% έκπτωση -> 92% της αρχικής

    printf("Total cost: %.2f EUR", total);
    // printf("Total cost: %.2f€", total); // για συστήματα που υποστηρίζουν Unicode

    return 0;
}
