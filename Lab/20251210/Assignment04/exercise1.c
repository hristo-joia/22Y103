// ’σκηση 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1
#define MAX_NAME 50

typedef struct bankAccount{
    char name[MAX_NAME];
    float ammount;
    int date; // σε μορφή ISO 8601 (YYYYMMDD)
} acc;

void scanAccounts(acc* accountsArr, int n){
    for (int account = 0; account<n; account++){
        printf("Enter depositor name: ");
        scanf("%s", accountsArr[account].name);

        printf("Enter deposit ammount: ");
        scanf("%f", &accountsArr[account].ammount);

        printf("Enter deposit date in YYYYMMDD format: ");
        scanf("%d", &accountsArr[account].date);
    }
    return;
}

void searchDepositor(acc* accountsArr, int n){
    char query[MAX_NAME];
    printf("Enter depositor name to search: ")
    scanf("%s", query);
}

int main(){
    acc* accounts = (acc*)malloc(N*sizeof(acc));
    scanAccounts(accounts, N);
    //printf("%s %g %d", accounts[0].name, accounts[0].ammount, accounts[0].date);

    return 0;
}
