// Άσκηση 6
#include <stdio.h>
#include <stdlib.h>

int** createTable(int rows, int cols) {
    // δημιουργεί έναν 2D πίνακα ακεραίων εισαγόμενων διαστάσεων
    int** table = (int**)malloc(rows * sizeof(int));
    for (int i = 0; i < cols; i++)
        *(table + i) = (int*)malloc(cols * sizeof(int));
    return table;
}

int* createArray(int cols) {
    // δημιουργεί έναν 1D πίνακα ακεραίων εισαγόμενων διαστάσεων
    int* arr = (int*)malloc(cols * sizeof(int));
    return arr;
}

void resetArray(int* arr, int cols) {
    // μηδενίζει έναν 1D πίνακα ακεραίων
    for (int i = 0; i < cols; i++)
        arr[i] = 0;
    return;
}

void scanTable(int** table, int rows, int cols) {
    // διαβάζει έναν 2D πίνακα μεγέθους (rows x cols)
    for (int i = 0; i < rows; i++) {      // για κάθε γραμμή
        for (int j = 0; j < cols; j++) {  // για κάθε στήλη
            scanf("%d", &table[i][j]);
        }
    }
    return;
}

void printTable(int** table, int rows, int cols) {
    // εκτυπώνει έναν 2D πίνακα μεγέθους (rows x cols)
    for (int i = 0; i < rows; i++) {      // για κάθε γραμμή
        for (int j = 0; j < cols; j++) {  // για κάθε στήλη
            printf("%d\t", table[i][j]);  // εκύπωσε το στοιχείο και έναν στηλοθέτη
        }
        printf("\n");  // πήγαινε στην επόμενη γραμμή
    }
}

void printArray(int* arr, int cols) {
    // εκτυπώνει έναν 1D πίνακα cols στηλών
    for (int i = 0; i < cols; i++) {  // για κάθε γραμμή
        printf("%d\t", arr[i]);       // εκύπωσε το στοιχείο και έναν στηλοθέτη
    }
    printf("\n");  // πήγαινε στην επόμενη γραμμή
}

int* sumColumns(int** table, int rows, int cols, int* sumArr) {
    // αθροίζει τις στήλες ενός 2D πίνακα και επιστρέφει τα αποτελέσματα σε έναν 1D πίνακα

    resetArray(sumArr, cols);  // μηδένισε όλα τα στοιχεία του πίνακα
    for (int column = 0; column < cols; column++) {
        for (int row = 0; row < rows; row++) {
            sumArr[column] += table[row][column];
        }
    }
    return sumArr;
}

int main() {
    int rows, cols;
    printf("Give table rows: ");
    scanf("%d", &rows);
    printf("Give table columns: ");
    scanf("%d", &cols);

    int** table = createTable(rows, cols);  // ο πίνακας όπου θα αποθηκευτούν οι είσοδοι

    printf("Give a (%dx%d) table of numbers by rows:\n", rows, cols);
    scanTable(table, rows, cols);

    printf("The entered table is:\n");
    printTable(table, rows, cols);

    int* sum = createArray(cols);
    sumColumns(table, rows, cols, sum);

    printf("The sum of its columns is:\n");
    printArray(sum, cols);

    return 0;
}
