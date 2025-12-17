// Άσκηση 3
#include <stdio.h>
#include <string.h>
#define MAX_STR 100
#define STORES 20
#define BOOKS 500

void scanStr(char* str, int limit) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
    fgets(str, limit, stdin);
    return;
}

void scanArray(char arr[][MAX_STR], int length) {
    // συμπλήρωσε τα αλφαριθμητικά δεδομένα του πίνακα arr
    for (int i = 0; i < length; i++) {
        do scanStr(arr[i], MAX_STR);
        while (strlen(arr[i]) < 2);  // το ελάχιστο μήκος ονόματος είναι 1 χαρακτήρας + \n
        arr[i][strlen(arr[i]) - 1] = '\0';  // διαγραφή του τελικού '\n'
    }
    return;
}

void printArray(char arr[][MAX_STR], int length) {
    // για κάθε στοιχείο ενός πίνακα αλφαριθμητικών εκτύπωσε τη θέση του και το όνομά του
    for (int i = 0; i < length; i++)
        printf("%d:\t%s\n", i, arr[i]);

    return;
}

void scanStore(int bookCount, int storeInv[bookCount], char bookCatalogue[][MAX_STR]) {
    //        πλήθος βιβλίων, πίνακας αποθέματος βιβλιοπωλείου,   κατάλογος βιβλίων
    // συμπλήρωσε τις πληροφορίες αποθέματος του βιβλιοπωλείου
    for (int book = 0; book < bookCount; book++) do {
            printf("How many copies of '%s' in stock? ", bookCatalogue[book]);
            scanf("%d", &storeInv[book]);
        } while (storeInv[book] < 0);  // δεν μπορεί να έχει αρνητικό απόθεμα

    return;
}

void scanInventory(int storeCount, char stores[][MAX_STR], int bookCount, char bookCatalogue[][MAX_STR], int globalInv[storeCount][bookCount]) {
    //       πλήθος βιβλιοπωλείων,  πίνακας βιβλιοπωλείων, πλήθος βιβλίων,            κατάλογος βιβλίων,     ολικός πίνακας αποθεμάτων
    for (int store = 0; store < storeCount; store++) {
        printf("Scanning bookstore '%s':\n", stores[store]);
        scanStore(bookCount, globalInv[store], bookCatalogue);
        // συμπλήρωσε bookCount βιβλία από τον κατάλογο bookCatalogue στον πίνακα αποθέματος του βιβλιοπωλείου store
    }
    return;
}

int searchCode(char query[], char arr[][MAX_STR], int size) {
    for (int code = 0; code < size; code++)  // για κάθε κωδικό βιβλίου
        if (strcmp(query, arr[code]) == 0)   // αν βρέθηκε ο τίτλος βιβλίου
            return code;                     // επίστρεψε τον κωδικό του

    return -1;  // αν δε βρέθηκε τέτοιο βιβλίο επίστρεψε -1
}

void printBooks(int storeCode, char books[][MAX_STR], int inventory[STORES][BOOKS]) {
    int found = 0;
    for (int book = 0; book < BOOKS; book++) {
        // για κάθε βιβλίο
        if (inventory[storeCode][book] > 0) {
            // αν είναι σε απόθεμα
            if (found == 0) {
                // αν αυτό είναι το πρώτο βιβλίο που βρέθηκε
                printf("The store is carrying these books:\n");  // γράψε αυτό το μήνυμα
                found = 1;
            }  // και μετά αυτό το μήνυμα για κάθε βιβλίο που θα βρεις
            printf("%d copies of %s\n", inventory[storeCode][book], books[book]);
        }
    }
    if (found == 0) printf("Store was found but is out of stock on all books.\n");  // αν δε βρέθηκε κανένα βιβλίο σε αυτό το βιβλιοπωλείο

    return;
}

void printBookstores(int bookCode, char bookstores[][MAX_STR], int inventory[STORES][BOOKS]) {
    int found = 0;
    for (int store = 0; store < STORES; store++) {
        // για κάθε βιβλιοπωλείο
        if (inventory[store][bookCode] > 0) {
            // αν έχει το βιβλίο σε απόθεμα
            if (found == 0) {
                // αν αυτό είναι το πρώτο βιβλιοπωλείο που βρέθηκε
                printf("The book was found in these stores:\n");
                found = 1;
            }
            printf("%s\t with %d copies\n", bookstores[store], inventory[store][bookCode]);
        }
    }
    if (found == 0) printf("Book was found but is out of stock everywhere.\n");  // αν δε βρέθηκε σε κανένα βιβλιοπωλείο

    return;
}

int main() {
    char storesArr[STORES][MAX_STR];
    char booksArr[BOOKS][MAX_STR];
    int inventory[STORES][BOOKS] = {0};

    printf("Give store names:\n");
    scanArray(storesArr, STORES);
    printf("\nThe stores entered are:\n");
    printArray(storesArr, STORES);

    printf("Give book titles:\n");
    scanArray(booksArr, BOOKS);
    printf("\nThe entered books are:\n");
    printArray(booksArr, BOOKS);

    scanInventory(STORES, storesArr, BOOKS, booksArr, inventory);

    char searchQuery[MAX_STR] = {0};

    printf("Give book title to search: ");
    do {
        scanStr(searchQuery, MAX_STR);
    } while (strlen(searchQuery) < 2);  // το ελάχιστο μήκος ονόματος είναι 1 χαρακτήρας + \n
    searchQuery[strlen(searchQuery) - 1] = '\0';  // διαγραφή του τελικού '\n'

    int code = searchCode(searchQuery, booksArr, BOOKS);  // ψάξε τον κωδικό του εισαγόμενου βιβλίου
    if (code == -1)
        printf("Book not found.\n");
    else {
        printBookstores(code, storesArr, inventory);
    }

    printf("Give bookstore name to search: ");
    do {
        scanStr(searchQuery, MAX_STR);
    } while (strlen(searchQuery) < 2);  // το ελάχιστο μήκος ονόματος είναι 1 χαρακτήρας + \n
    searchQuery[strlen(searchQuery) - 1] = '\0';  // διαγραφή του τελικού '\n'

    code = searchCode(searchQuery, storesArr, STORES);  // ψάξε τον κωδικό του εισαγόμενου βιβλιοπωλείου
    if (code == -1)
        printf("Store not found.\n");
    else
        printBooks(code, booksArr, inventory);

    return 0;
}
