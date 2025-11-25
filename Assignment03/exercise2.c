#include <stdio.h>
#define N 3

void scanMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {      // για κάθε γραμμή
        for (int j = 0; j < cols; j++) {  // για κάθε στήλη
            scanf("%d", &matrix[i][j]);   // διάβασε το στοιχείο
        }
    }
    return;
}

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {       // για κάθε γραμμή
        for (int j = 0; j < cols; j++) {   // για κάθε στήλη
            printf("%d\t", matrix[i][j]);  // εκτύπωσε το στοιχείο και έναν στηλοθέτη
        }
        printf("\n");  // πήγαινε στην επόμενη γραμμή
    }
}

int diagonal(int rows, int cols, int matrix[rows][cols]) {
    int sum = 0;
    if (rows == cols) {  // μόνο τα τετραγωνικά μπορούν να είναι διαγώνια
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == j) {
                    sum += matrix[i][j];
                    printf("%d\t", matrix[i][j]);
                } else
                    printf("0\t");
            }
            printf("\n");
        }
    }
    return sum;
}

int upperTriang(int rows, int cols, int matrix[rows][cols]) {
    int sum = 0;
    if (rows == cols) {  // μόνο τα τετραγωνικά μπορούν να είναι τριγωνικά
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (j >= i) {
                    sum += matrix[i][j];
                    printf("%d\t", matrix[i][j]);
                } else
                    printf("0\t");
            }
            printf("\n");
        }
    }
    return sum;
}

int lowerTriang(int rows, int cols, int matrix[rows][cols]) {
    int sum = 0;
    if (rows == cols) {  // μόνο τα τετραγωνικά μπορούν να είναι τριγωνικά
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (j <= i) {
                    sum += matrix[i][j];
                    printf("%d\t", matrix[i][j]);
                } else
                    printf("0\t");
            }
            printf("\n");
        }
    }
    return sum;
}

void printTranspose(int rows, int cols, int matrix[rows][cols]) {
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[N][N];
    int sum;

    printf("Input a %dx%d matrix by rows (any extra elements will be ignored):\n", N, N);
    scanMatrix(N, N, matrix);

    printf("\nInputted matrix:\n");
    printMatrix(N, N, matrix);

    printf("\n\nThe diagonal of that matrix is:\n");
    sum = diagonal(N, N, matrix);
    printf("The sum of its elements is %d\n", sum);

    printf("\n\nThe upper triangular of that matrix is:\n");
    sum = upperTriang(N, N, matrix);
    printf("The sum of its elements is %d\n", sum);

    printf("\n\nThe lower triangular of that matrix is:\n");
    sum = lowerTriang(N, N, matrix);
    printf("The sum of its elements is %d\n", sum);

    printf("\n\nThe transpose of that matrix is:\n");
    printTranspose(N, N, matrix);

    return 0;
}
