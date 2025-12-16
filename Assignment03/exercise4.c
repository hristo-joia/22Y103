// Άσκηση 4
#include <stdio.h>
#include <string.h>
#define N 100
#define MAX_WORD_LEN 13

void scanSentence(char input[N][MAX_WORD_LEN]) {
    for (int i = 0; i < N; i++) {
        scanf("%s", input[i]);  // διάβασε μία-μία τις λέξεις και αποθήκευσέ τες στον πίνακα input
        char lastChar = input[i][strlen(input[i]) - 1];
        if (lastChar < 65 || lastChar > 123 || (58 <= lastChar && lastChar <= 64))
            input[i][strlen(input[i]) - 1] = '\0';
        // αν ο τελευταίος χαρακτήρας δεν είναι γράμμα (πχ. στίξη), σβησ' τον
    }
    return;
}
void generateHist(int hist[MAX_WORD_LEN], char input[N][MAX_WORD_LEN]) {
    printf("\n");
    for (int i = 0; i < N; i++)
        hist[strlen(input[i])]++;  // για κάθε λέξη μήκους strlen(input[i]) πρόσθεσε 1 στο αντίστοιχο κελί

    return;
}

void printHist(int hist[MAX_WORD_LEN]) {
    printf("\nWord Length\t| Number of Occurances\n");
    for (int i = 1; i < MAX_WORD_LEN + 1; i++) {
        printf("%d\t\t| ", i);  // μήκος λέξης
        for (int j = 0; j < hist[i]; j++)
            printf("*");  // hist[i] αστεράκια

        printf("\n");
    }
}

int main() {
    char input[N][MAX_WORD_LEN];
    int hist[MAX_WORD_LEN + 1] = {0};
    printf("Give %d words to generate a histogram of word lengths:\n", N);
    scanSentence(input);
    generateHist(hist, input);

    printHist(hist);

    return 0;
}
