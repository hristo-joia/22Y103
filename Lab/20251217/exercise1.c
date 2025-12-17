// ¶σκηση 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1
#define MAX_NAME 50

typedef struct bankAccount{
    char* name;
    float ammount;
    int date; // σε μορφή ISO 8601 (YYYYMMDD)
} acc;

void scanAccounts(acc* accountsArr, int n){
    char name[MAX_NAME];
    for (int account = 0; account<n; account++){
        printf("Enter depositor name: ");
        fgets(name, MAX_NAME, stdin);

        name[strcspn(name, "\n")] = '\0';

        accountsArr[account].name = (char*)malloc((strlen(name)+1)*sizeof(char));
        strcpy(accountsArr[account].name, name);
        printf("Enter deposit ammount: ");
        scanf("%f", &accountsArr[account].ammount);

        printf("Enter deposit date in YYYYMMDD format: ");
        scanf("%d", &accountsArr[account].date);
    }
    return;
}

void searchDepositor(acc* accountsArr, int n){
    char query[MAX_NAME];
    printf("Enter depositor name to search: ");
    char c;
    while((c = getchar()) != '\n' && c != EOF);

    fgets(query, MAX_NAME, stdin);
    query[strcspn(query, "\n")] = '\0';

    float sum = 0;
    int found = 0;
    for(int account = 0; account<n; account++){
        if (strcmp(accountsArr[account].name, query) == 0){
            found = 1;
            printf("Account #%d\n", account);
            printf("Account Name:\t%s\n", accountsArr[account].name);
            printf("Ammount:\t%g\n", accountsArr[account].ammount);
            printf("Date:\t\t%d\n", accountsArr[account].date);

            sum += accountsArr[account].ammount;
        }
    }
    if (found) printf("The sum of the deposits is %g", sum);
    else printf("Couldn't find any deposit with name %s", query);
}

int main(){
    acc* accounts = (acc*)malloc(N*sizeof(acc));
    scanAccounts(accounts, N);
    //printf("%s %g %d", accounts[0].name, accounts[0].ammount, accounts[0].date);
    searchDepositor(accounts, N);
    return 0;
}
