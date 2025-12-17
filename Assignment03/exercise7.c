// Άσκηση 7
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20
#define MAX_MISTAKES 7

#ifdef _WIN32 _WIN64
#define clear system("cls")  // για windows
#else
#define clear system("clear")  // για Unix-like
#endif

void scanStr(char* str, int limit) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
    fgets(str, limit, stdin);
    return;
}

char hangmanPics[8][70] = {
    "  +---+\n"
    "  |   |\n"
    "      |\n"
    "      |\n"
    "      |\n"
    "      |\n"
    "=========\n",
    "  +---+\n"
    "  |   |\n"
    "(._.) |\n"
    "      |\n"
    "      |\n"
    "      |\n"
    "=========\n",
    "  +---+\n"
    "  |   |\n"
    "(._.) |\n"
    "  |   |\n"
    "      |\n"
    "      |\n"
    "=========\n",
    "  +---+\n"
    "  |   |\n"
    "(._.) |\n"
    " /|   |\n"
    "      |\n"
    "      |\n"
    "=========\n",
    "  +---+\n"
    "  |   |\n"
    "(;-;) |\n"
    " /|\\  |\n"
    "      |\n"
    "      |\n"
    "=========\n",
    "  +---+\n"
    "  |   |\n"
    "(;-;) |\n"
    " /|\\  |\n"
    " /    |\n"
    "      |\n"
    "=========\n",
    "  +---+\n"
    "  |   |\n"
    "(;-;) |\n"
    " /|\\  |\n"
    " / \\  |\n"
    "      |\n"
    "=========\n",
    "  +---+\n"
    "  |   |\n"
    "(X_X) |\n"
    " /|\\  |\n"
    " / \\  |\n"
    "      |\n"
    "=========\n"};

char hangmanHappyPics[7][70] = {
    "  +---+\n"
    "  |   |\n"
    "(^_^) |\n"
    "      |\n"
    "      |\n"
    "      |\n"
    "=========\n",
    "  +---+\n"
    "  |   |\n"
    "(^_^) |\n"
    "      |\n"
    "      |\n"
    "      |\n"
    "=========\n",
    "  +---+\n"
    "  |   |\n"
    "(^_^) |\n"
    "  |   |\n"
    "      |\n"
    "      |\n"
    "=========\n",
    "  +---+\n"
    "  |   |\n"
    " \\O   |\n"
    "  |   |\n"
    "      |\n"
    "      |\n"
    "=========\n",
    "  +---+\n"
    "  |   |\n"
    " \\O/  |\n"
    "  |   |\n"
    "      |\n"
    "      |\n"
    "=========\n",
    "  +---+\n"
    "  |   |\n"
    " \\O/  |\n"
    "  |   |\n"
    " /    |\n"
    "      |\n"
    "=========\n",
    "  +---+\n"
    "  |   |\n"
    " \\O/  |\n"
    "  |   |\n"
    " / \\  |\n"
    "      |\n"
    "=========\n"};

void lowerCase(char word[]) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (word[i] >= 65 && word[i] <= 90) {
            word[i] += 32;  // κάθε μικρό γράμμα στον κώδικα ASCII απέχει κατά 32 από το αντίστοιχο κεφαλαίο
        }
    }

    return;
}

void putWord(char word[], int wordMask[]) {
    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        if (wordMask[i])
            putchar(word[i]);
        else
            putchar('_');
    }
    return;
}

void printMistakes(char mistakesArr[]) {
    int length = strlen(mistakesArr);
    for (int attempt = 0; attempt < length; attempt++)
        printf("%c, ", mistakesArr[attempt]);
    printf("\b\b \n");
    return;
}

int matchLetters(char word[], char guess, int wordMask[]) {
    int found = 0;
    int length = strlen(word);
    for (int letter = 0; letter <= length; letter++) {
        if (word[letter] == guess) {
            wordMask[letter] = 1;
            found++;
        }
    }
    return found;
}

int checkWin(int wordMask[], int length) {
    int won = 1;
    for (int letter = 0; letter < length; letter++)
        if (wordMask[letter] == 0)
            won = 0;
    return won;
}

void ammendMistakes(char mistakesArr[], char attempt) {
    int end = strlen(mistakesArr);
    mistakesArr[end] = attempt;
    mistakesArr[end + 1] = 0;
    return;
}

int main() {
    char word[MAX_WORD_LEN + 1];
    int wordMask[MAX_WORD_LEN] = {0};
    char wrongLetters[8] = "";
    char letter;
    printf("Give a word to play: ");
    scanStr(word, MAX_WORD_LEN);
    lowerCase(word);
    clear;
    int length = strlen(word);

    int mistakesLeft = MAX_MISTAKES;
    int won = 0;
    do {
        printf("%s", hangmanPics[MAX_MISTAKES - mistakesLeft]);
        printf("Wrong letters: ");

        // printf("%s\n", wrongLetters);
        printMistakes(wrongLetters);
        putWord(word, wordMask);
        printf("\n%d mistakes remaining.\n\n", mistakesLeft);

        printf("Enter your guess:\n");
        do {
            scanf("%c", &letter);
        } while ((letter < 65 || letter > 90) && (letter < 97 || letter > 121));

        if (letter >= 65 && letter <= 90)
            letter += 32;  // κάθε μικρό γράμμα στον κώδικα ASCII απέχει κατά 32 από το αντίστοιχο κεφαλαίο

        if (matchLetters(word, letter, wordMask) == 0) {
            mistakesLeft--;
            ammendMistakes(wrongLetters, letter);
        }

        won = checkWin(wordMask, length);

    } while (mistakesLeft > 0 && won == 0);

    if (won)
        printf("\n%s\nCongratulations! The word was %s.\n\n", hangmanHappyPics[MAX_MISTAKES - mistakesLeft], word);
    else
        printf("\n%s\nYou lost. The word was %s.\n", hangmanPics[7], word);

    return 0;
}
