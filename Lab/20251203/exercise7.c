// Άσκηση 7
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20
#define MAX_ATTEMPTS 7

#ifdef _WIN32 _WIN64
    #define clear system("cls") // για windows
#else
    #define clear system("clear") // για Unix-like
#endif

char HANGMANPICS[7][70] = {
"  +---+\n"
"  |   |\n"
"      |\n"
"      |\n"
"      |\n"
"      |\n"
"=========\n",
"  +---+\n"
"  |   |\n"
"  O   |\n"
"      |\n"
"      |\n"
"      |\n"
"=========\n",
"  +---+\n"
"  |   |\n"
"  O   |\n"
"  |   |\n"
"      |\n"
"      |\n"
"=========\n",
"  +---+\n"
"  |   |\n"
"  O   |\n"
" /|   |\n"
"      |\n"
"      |\n"
"=========\n",
"  +---+\n"
"  |   |\n"
"  O   |\n"
" /|\  |\n"
"      |\n"
"      |\n"
"=========\n",
"  +---+\n"
"  |   |\n"
"  O   |\n"
" /|\  |\n"
" /    |\n"
"      |\n"
"=========\n",
"  +---+\n"
"  |   |\n"
"  O   |\n"
" /|\  |\n"
" / \  |\n"
"      |\n"
"=========\n"};

void lowerCase(char word[]){
    int len = strlen(word);
    for (int i=0; i<len; i++){
        if (word[i]>=65&&word[i]<=90){
            word[i]+=32; // κάθε μικρό γράμμα στον κώδικα ASCII απέχει κατά 32 από το αντίστοιχο κεφαλαίο
        }
    }

    return;
}

void putWord(char word[], char wordMask[]){
    int length = strlen(word);
    for(int i=0; i<length; i++){
        if (wordMask[i])
            putchar(word[i]);
        else
            putchar('_');
    }
    return;
}

void printAttempts(char* attemptsArr){
    int length = strlen(attemptsArr);
    for (int attempt=0; attempt<length; attempt++)
        printf("%c, ", attemptsArr+attempt);
    printf("\b\b ");
    return;
}



int main(){
    char word[MAX_WORD_LEN+1];
    char wordMask[MAX_WORD_LEN]={0};
    char attempts[8]="fdsa";
    char letter;

    printf("Give a word to play: \n");
    scanf("%s", word);
    lowerCase(word);
    clear;

    for (int attempts=MAX_ATTEMPTS; attempts>0; attempts--){
        printf("%s", HANGMANPICS[0]);
        printf("Attempted letters: ");

        //printAttempts(attempts);
        printf("%s", attempts);
        printf("\n");

        putWord(word, wordMask);
        printf("\n%d attempts remaining.\n", attempts);

    }


    return 0;
}
