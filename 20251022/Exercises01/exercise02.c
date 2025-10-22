#include <stdio.h>

//Άσκηση 2

int main(){
    int h, min, sec;

    do {
        printf("Give time in hh:mm:ss format: ");
        scanf("%d:%d:%d", &h, &min, &sec);
        // επικυροποίηση εισαγόμενων τιμών
    } while ((h>24 || min>60 || sec>60) || (h<0 || min<0 || sec<0));

    // υπολογισμός δευτερολέπτων από την αρχή της ημέρας
    int secFromMidnight;
    secFromMidnight = h*60*60 + min*60 + sec;

    // υπολογισμός δευτερολέπτων μέχρι τα μεσάνυχτα
    int sec2Midnight;
    sec2Midnight = 24*60*60 - secFromMidnight; //24h * 60min * 60sec σε μία ημέρα
    h = sec2Midnight / (60*60); // υπολογισμός ωρών
    sec2Midnight = sec2Midnight - (h*60*60);

    min = sec2Midnight / 60; // υπολογισμός λεπτών

    sec2Midnight = sec2Midnight - (min*60);

    sec = sec2Midnight;

    printf("%02d:%02d:%02d until midnight", h, min, sec);

    return 0;
}
