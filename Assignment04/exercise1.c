// Άσκηση 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1
#define MAX_NAME 50

void scanStr(char* str, int limit) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
    fgets(str, limit, stdin);
    return;
}

typedef struct bankAccount {
    char* name;
    float ammount;
    int date;  // σε μορφή ISO 8601 (YYYYMMDD)
} acc;

int checkDate(int date) {
    int y = date / 10000;
    int m = date % 10000 / 100;
    int d = date % 100;

    int leap;

    if (y % 400 == 0)
        leap = 1;
    else if (y % 100)
        leap = 0;
    else if (y % 4)
        leap = 1;
    else
        leap = 0;

    if (m < 1 || m > 12) return 0;
    switch (m) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (d < 1 || d > 31) return 0;
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            if (d < 1 || d > 30) return 0;
            break;

        case 2:
            if (leap) {
                if (d < 1 || d > 29)
                    return 0;
            } else if (d < 1 || d > 28)
                return 0;
            break;
    }
    return 1;
}

void scanAccounts(acc* accountsArr, int n) {
    char name[MAX_NAME];

    for (int account = 0; account < n; account++) {
        printf("Enter depositor name: ");
        scanStr(name, MAX_NAME);
        name[strcspn(name, "\n")] = '\0';

        accountsArr[account].name = (char*)malloc((strlen(name) + 1) * sizeof(char));
        strcpy(accountsArr[account].name, name);
        printf("Enter deposit ammount: ");
        scanf("%f", &accountsArr[account].ammount);

        do {
            printf("Enter deposit date in YYYYMMDD format: ");
            scanf("%d", &accountsArr[account].date);
        } while (checkDate(accountsArr[account].date) == 0);
    }
    return;
}

void searchDepositor(acc* accountsArr, int n) {
    char query[MAX_NAME];

    printf("Enter depositor name to search: ");

    scanStr(query, MAX_NAME);
    query[strcspn(query, "\n")] = '\0';

    float sum = 0;
    int found = 0;
    for (int account = 0; account < n; account++) {
        if (strcmp(accountsArr[account].name, query) == 0) {
            found = 1;
            printf("Account #%d\n", account);
            printf("Account Name:\t%s\n", accountsArr[account].name);
            printf("Ammount:\t%g\n", accountsArr[account].ammount);
            printf("Date:\t\t%d\n", accountsArr[account].date);

            sum += accountsArr[account].ammount;
        }
    }
    if (found)
        printf("The sum of the deposits is %g", sum);
    else
        printf("Couldn't find any deposit with name %s", query);
}

int main() {
    acc accounts[N];
    scanAccounts(accounts, N);
    // printf("%s %g %d", accounts[0].name, accounts[0].ammount, accounts[0].date);
    searchDepositor(accounts, N);
    return 0;
}
