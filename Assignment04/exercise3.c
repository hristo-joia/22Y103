// Άσκηση 3
#include <stdio.h>
#include <string.h>

#define N 10
#define M 10

typedef struct word_pair {
    char word[M];
    int length;
} wordPair;

/*Μία συνάρτηση που θα ζητάει από τον χρήστη και θα γεμίζει τον πίνακα με Ν
αλφαριθμητικά, και για κάθε αλφαριθμητικό θα υπολογίζει και θα αποθηκεύει
στην αντίστοιχη θέση το μήκος του. Το μήκος του αλφαριθμητικού θα πρέπει
να υπολογίζεται με δική σας συνάρτηση και όχι με συνάρτηση της βιβλιοθήκης
της C. Η συνάρτηση να δηλωθεί ως void initialize(struct word_pair
word_table[], int size) (με size συμβολίζεται ο αριθμός των γραμμών του
πίνακα). Η είσοδος των συμβολοσειρών να γίνει με αμυντικό
προγραμματισμό.*/
void initialise(wordPair wordArr[], int size) {
    for (int i = 0; i < size; i++) {
        scanStr(wordArr[i].word, M);
        wordArr[i].length = strlen(wordArr[i].word);
    }
    return;
}

/*Μία συνάρτηση που θα δέχεται σαν είσοδο δύο αλφαριθμητικά, και θα
αντικαθιστά κάθε εμφάνιση του πρώτου αλφαριθμητικού στα αλφαριθμητικά
του πρώτου πίνακα με το δεύτερο αλφαριθμητικό. Η συνάρτηση να δηλωθεί
ως :
void replace(struct word_pair word_table[], int size, char search_string[M],
char replacement_string[M]) (με size συμβολίζεται ο αριθμός των γραμμών
του πίνακα, search_string το αλφαριθμητικό που αναζητούμε, και
replacement_string το αλφαριθμητικό με το οποίο γίνεται η αντικατάσταση) .*/
void replace(wordPair wordArr[], int size, char searchString[M], char replacementString[M]);

/*Μία συνάρτηση που δοθείσης ενός αλφαριθμητικού εισόδου θα εντοπίζει και
θα εκτυπώνει όλες τις γραμμές του πίνακα που την περιέχουν σαν
υποσυμβολοσειρά (ο όρος υπονοεί συνεχόμενες εμφανίσεις των συμβόλων)
και σαν υποακολουθία (ο όρος δεν απαιτεί συνεχόμενες εμφανίσεις). Η
συνάρτηση να δηλωθεί σαν void sub_string_sequence(struct word_pair
word_table[], char search_string[M]) (με size συμβολίζεται ο αριθμός των
γραμμών του πίνακα, με search_string το αλφαριθμητικό που αναζητούμε).*/
void substringSequence(wordPair wordArr[], char searchString[M]);

int main() {
    wordPair wordArray[N];

    initialise(wordArray, N);

    return 0;
}
