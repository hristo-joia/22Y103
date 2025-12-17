#include <stdio.h>
#include <string.h>
#define M 100

void scanStr(char* str, int limit) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
    fgets(str, limit, stdin);
    return;
}

int rmPunctuation(char input[]) {
    int length = strlen(input);
    char lastChar = input[strlen(input) - 1];
    if (lastChar < 65 || lastChar > 123 || (58 <= lastChar && lastChar <= 64)) {
        // αν ο τελευταίος χαρακτήρας δεν είναι γράμμα (πχ. στίξη), σβησ' τον
        input[strlen(input) - 1] = '\0';
        return 1;
    }
    return 0;
}

void findWord(char word[], char str[]) {
    int first = 1;
    char* temp = str;
    // η συνάρτηση strstr επιστρέφει δείκτη στην πρώτη εμφάνιση του word στο temp
    // ο βρόχος επαναλαμβάνεται μέχρι να επιστρέψει δείκτη NULL
    while (temp = strstr(temp, word)) {
        if (first) {
            printf("The word '%s' was found at index(es): ", word);  // μορφοποίηση
            first = 0;
        }
        printf("%d ", (int)(temp - str));  // η θέση μνήμης όπου εμφανίζεται το word είναι η temp, ενώ το word αρχίζει από τη θέση str
        // άρα κάνοντας temp - str βρίσκουμε τη θέση εμφάνισης της word μέσα στο str
        temp += strlen(word);  // «κόβουμε» το word από την αρχή του str
    }

    printf("\n");
    return;
}

int main() {
    char A[M];  // οι λέξεης που θα αναζητηθούν
    char B[M];  // το αλφαριθμιτικό στο οποίο θα αναζητηθούν

    printf("Give string A with words to search: ");
    scanStr(A, M);
    rmPunctuation(A);

    printf("Give string B in which to search words: ");
    scanStr(B, M);

    char* word = strtok(A, " ");  // βρες την πρώτη λέξη του A
    while (word != NULL) {
        rmPunctuation(word);  // σβήσε τυχών στίξη
        findWord(word, B);
        word = strtok(NULL, " ");  // βρες την επόμενη λέξη
    }
    return 0;
}