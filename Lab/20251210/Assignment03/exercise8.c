// ’σκηση 8
#include <stdio.h>
#define WINGS 8
#define ROOMS 20

#define AVAILABILITY 1
#define RESERVE 2
#define CANCEL 3
#define EXIT 4

void printAvailable(int roomsArr[][ROOMS]){
    printf("Wing\t\t"); // ετικέτες πτέρυγας
    for (int wing = 0; wing<WINGS; wing++)
        printf("%d\t", wing+1); // για τον χρήστη η αρίθμιση ξεκινάει από το 1, αλλά για το πρόγραμμα από το 0
    printf("\nRoom");
    for (int room = 0; room<ROOMS; room++){
        printf("\t%d\t", room+1); // ετικέτα δωματίου
        for (int wing=0; wing<WINGS; wing++){
            printf("%s", roomsArr[wing][room] == 0 ? "A\t" : "_\t"); // εκτύπωσε A αν είναι διαθέσιμο, αλλιώς _
        }
        printf("\n");
    }
}

void reserve(int roomsArr[][ROOMS]){
    int wing, room;
    do{
    printf("Select the wing of the room to be reserved (1-%d): ", WINGS);
    scanf("%d", &wing);
    } while(wing<1||wing>WINGS);  // επικύρωση εισόδου
    wing--; // για τον χρήστη η αρίθμιση ξεκινάει από το 1, αλλά για το πρόγραμμα από το 0

    do{
    printf("Select a room to reserve in wing %d (1-%d): ", wing, ROOMS);
    scanf("%d", &room);
    } while(room<1||room>ROOMS);
    room--;

    if (roomsArr[wing][room]){ // αν το δωμάτιο είναι ήδη κρατημένο
        printf("This room already reserved.\n");
    } else {
        roomsArr[wing][room]=1; // κάνε κράτηση στο δωμάτιο
        printf("Reserved room %d in wing %d.\n", room+1, wing+1);
    }
}

void cancelReservation(int roomsArr[][ROOMS]){
    int wing, room;
    do{
    printf("Select the wing of the room reservation to be cancelled (1-%d): ", WINGS);
    scanf("%d", &wing);
    } while(wing<1||wing>WINGS); // επικύρωση εισόδου
    wing--; // για τον χρήστη η αρίθμιση ξεκινάει από το 1, αλλά για το πρόγραμμα από το 0

    do{
    printf("Select a room in wing %d to cancel the reservation (1-%d): ", wing, ROOMS);
    scanf("%d", &room);
    } while(room<1||room>ROOMS);
    room--;

    if (roomsArr[wing][room]){ // αν το δωμάτιο είναι κρατημένο
        roomsArr[wing][room]=0;
        printf("Cancelled the reservation of room %d in wing %d.\n", room+1, wing+1);
    } else {
        printf("This room isn't reserved.\n");
    }
}

int main(){
    int reservations[WINGS][ROOMS] = {0}; // θεώρησε όλα τα δωμάτια διαθέσιμα
    int option; // η επιλογή που θα δώσει ο χρήστης
    while (1){ // ατέρμων βρόχος μέχρι ο χρήστης να επιλέξει τερματισμό
        printf("Select one of the following options:\n"
               "1) Show available rooms (default)\n"
               "2) Make a new reservation\n"
               "3) Cancel a reservation\n"
               "4) Exit\n");
        do
            scanf("%d", &option);
        while(option<0); // επικύρωση εισόδου

        switch(option){
        default: // οποιαδήποτε
        case AVAILABILITY:
            printAvailable(reservations);
            break;
        case RESERVE:
            reserve(reservations); break;
        case CANCEL:
            cancelReservation(reservations); break;
        case EXIT:
            return 0;
        }
    }
    return 0;
}
