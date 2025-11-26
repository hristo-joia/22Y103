#include <stdio.h>
#include <string.h>
#define N 50
#define M 13

void scanSentence(char input[N][M]) {
    for (int i = 0; i < N; i++) {
        scanf("%s", input[i]);
        char lastChar = input[i][strlen(input[i])-1];
        if (lastChar<65 || lastChar>123 ||(58<=lastChar&&lastChar<=64))
            input[i][strlen(input[i])-1] = '\0';
        // αν ο τελευταίος χαρακτήρας δεν είναι γράμμα (πχ. στίξη), σβησ' τον
    }
    return;
}
void generateHist(int hist[M], char input[N][M]){
    printf("\n");
    for (int i=0; i<N; i++){
        hist[strlen(input[i])]++;
    }
    return;
}

void printHist(int hist[M]){
    printf("\nWord Length\t| Number of Occurances\n");
    for (int i=1; i<M+1; i++){;
        printf("%d\t\t| ", i);
            for (int j=0; j<hist[i]; j++){
                printf("*");
            }
        printf("\n");
    }
}

int main() {
    char input[N][M];
    int hist[M+1]={0};
    printf("Give %d words to generate a histogram of word lengths:\n", N)
    ;scanSentence(input);
    generateHist(hist, input);

    printHist(hist);

    return 0;
}
