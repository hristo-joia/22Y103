// Άσκηση 3
#include <stdio.h>
#include <string.h>
#define M 100

void scanArray(char arr[][M], int length){
    for (int i=0; i<length; i++){
        do{
            // printf("Scanning %d: ", i);
            fgets(arr[i], M, stdin);
        } while(strlen(arr[i])<2); // το ελάχιστο μήκος ονόματος είναι 1 χαρακτήρας + \n
        arr[i][strlen(arr[i])-1]='\0'; // διαγραφή του τελικού \n
    }
    return;
}

void printArray(char arr[][M], int length){
    for (int i=0; i<length; i++){
        printf("%d:\t%s\n", i, arr[i]);
    }
    return;
}
void scanStore(int store, int bookCount, int inv[bookCount], char books[][M]){
    for (int book=0; book<bookCount; book++){
        printf("How many copies of '%s' in stock? ", books[book]);
    }
    return;
}

void scanInventory(int storeCount, char stores[][M], int bookCount, char books[][M], int inv[storeCount][bookCount]){
    for (int store=0; store<storeCount; store++){
        printf("Scanning bookstore '%s':\n", stores[store]);
        scanStore(store, bookCount, inv[store], books);
    }
    return;
}

int main(){
    char stores[20][M];
    char books[500][M];
    int inventory[20][500];

    printf("Give store names:\n");
    scanArray(stores, 20);
    printf("\nThe stores entered are:\n");
    printArray(stores, 20);

    printf("Give book titles:\n");
    scanArray(books, 5);//00);
    printf("\nThe entered books are:\n");
    printArray(books, 5);//00);

    scanInventory(20, stores, 500, books, inventory);

    return 0;
}
