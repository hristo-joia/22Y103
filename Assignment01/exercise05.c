#include <stdio.h>

// Άσκηση 5

int main() {
    int mon;   // αριθμός μήνα
    int feb;   // ημέρες Φεβρουαρίου
    int days;  // ημέρες μήνα

    do {
        printf("Give month number (1-12): ");
        scanf("%d", &mon);
    } while (mon < 1 || mon > 12);  // επικύρωση αριθμού μήνα

    // ανάγνωση ημερών μήνα
    switch (mon) {
        // περιπτώσεις μηνών με 31 ημέρες
        case 1:  // Ιανουάριος
            /* 31 + 28 - 50 = 9, άρα πρέπει να ρωτηθούν οι ημέρες του
            Φεβρουαρίου για ημερομηνίες μετά τις 9 Ιαν */
            /* Για λόγους απλότητας θα ρωτούνται για κάθε
            ημερομηνία του Ιανουαρίου */
            do {
                printf("Does February have 28 or 29 days? (28/29): ");
                scanf("%d", &feb);
            } while (feb != 28 && feb != 29);  // επικύρωση ημερών Φεβρουαρίου
        case 3:  // υπόλοιπες περιπτώσεις με 31 ημέρες
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            do {
                printf("Give number of days (1-31): ");
                scanf("%d", &days);
            } while (days < 1 || days > 31);  // επικύρωση αριθμού ημερών
            break;

        // περιπτώσεις μηνών με 30 ημέρες
        case 4:
        case 6:
        case 9:
        case 11:
            do {
                printf("Give number of days (1-30): ");
                scanf("%d", &days);
            } while (days < 1 || days > 30);
            break;

        case 2:  // Φεβρουάριος
            do {
                printf("Does February have 28 or 29 days? (28/29): ");
                scanf("%d", &feb);
            } while (feb != 28 && feb != 29);  // επικύρωση ημερών Φεβρουαρίου

            do {
                if (feb == 28)
                    printf("Give number of days (1-28): ");
                else
                    printf("Give number of days (1-29): ");
                scanf("%d", &days);
            } while (days < 1 || days > feb);
            break;
    }

    days += 50;  // 50 μέρες μετά
    // πχ. 5 Μαρτίου -> 55 Μαρτίου

    int invalid = 1;

    while (invalid) {  // διόρθωση υπερχείλισης ημερομηνίας,
                       // πχ. 55 Μαρτίου -> 24 Απριλίου

        if (mon > 12) mon = 1;  // διόρθωση υπερχείλισης αριθμού μήνα

        switch (mon) {
            case 1:  // περιπτώσεις μηνών με 31 ημέρες
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if (days > 31) {  // άκυρη ημερομηνία
                    days -= 31;
                    mon += 1;
                } else
                    invalid = 0;  // έγκυρη ημερομηνία
                break;

            case 4:  // περιπτώσεις μηνών με 30 ημέρες
            case 6:
            case 9:
            case 11:
                if (days > 30) {
                    days -= 30;
                    mon += 1;
                } else
                    invalid = 0;
                break;

            case 2:  // Φεβρουάριος
                if (days > feb) {
                    days -= feb;
                    mon += 1;
                } else
                    invalid = 0;
                break;
        }
    }

    printf("%d/%d\n", mon, days);
    return 0;
}
