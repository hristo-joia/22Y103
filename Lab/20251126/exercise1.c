// Άσκηση 1
#include <stdio.h>
#define N 5

void scanTable(int rows, int cols, int table[rows][cols]) {
    // διαβάζει έναν πίνακα μεγέθους (rows x cols)
    for (int i = 0; i < rows; i++) {      // για κάθε γραμμή
        for (int j = 0; j < cols; j++) {  // για κάθε στήλη
            scanf("%d", &table[i][j]);
        }
    }
    return;
}

void printTable(int rows, int cols, int table[rows][cols]) {
    // εκτυπώνει έναν πίνακα μεγέθους (rows x cols)
    for (int i = 0; i < rows; i++) {      // για κάθε γραμμή
        for (int j = 0; j < cols; j++) {  // για κάθε στήλη
            printf("%d\t", table[i][j]);  // εκύπωσε το στοιχείο και έναν στηλοθέτη
        }
        printf("\n");  // πήγαινε στην επόμενη γραμμή
    }
}

void deleteCross(int rows, int cols, int tablein[rows][cols], int tableout[rows - 1][cols - 1], int del) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i < del) {      // πάνω από τη διαγραφόμενη στήλη
                if (j < del) {  // αριστερά της διαγραφόμενης στήλης
                    tableout[i][j] = tablein[i][j];
                } else {  // δεξιά της διαγραφόμενης στήλης
                    tableout[i][j] = tablein[i][j + 1];
                }
            } else {            // κάτω από τη διαγραφόμενη στήλη
                if (j < del) {  // αριστερά της διαγραφόμενης στήλης
                    tableout[i][j] = tablein[i + 1][j];
                } else {  // δεξιά της διαγραφόμενης στήληςσ
                    tableout[i][j] = tablein[i + 1][j + 1];
                }
            }
        }
    }
    return;
}

int main() {
    // παράδειγμα πίνακα για αποσφαλμάτωση
    int table1[5][5] = {{11, 12, 13, 14, 15}, {21, 22, 23, 24, 25}, {31, 32, 33, 34, 35}, {41, 42, 43, 44, 45}, {51, 52, 53, 54, 55}};
    // int table1[N][N];
    int table2[N - 1][N - 1];

    printf("Input a %dx%d table by rows:\n", N, N);

    // scanTable(5, 5, table1);  // διάβασε τον αρχικό πίνακα

    printf("Inputted table:\n");
    printTable(N, N, table1);  // εμφ'ανισε τον αρχικό πίνακα

    int x;
    do {
        printf("Give a number to delete that row and column [1-%d]: ", N);
        scanf("%d", &x);  // διάβασε μέγεθος πίνακα
    } while (x < 1 || x > N);
    x--;  // η πρώτη γραμμή/στήλη βρίσκεται στη θέση 0 κ.ο.κ.

    deleteCross(N, N, table1, table2, x);  // σβήσε σταυροειδώς τη γραμμή και στήλη x

    printf("The table without row %d and column %d is:\n", x + 1, x + 1);
    printTable(N - 1, N - 1, table2);  // εμφάνισε τον τελικό πίνακα
    return 0;
}
