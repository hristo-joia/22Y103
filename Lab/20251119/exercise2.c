#include <stdio.h>

void scanMatrix(int rows, int cols, int matrix[rows][cols]){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    return;
}

void printMatrix(int rows, int cols, int matrix[rows][cols]){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int diagonal(int rows, int cols, int matrix[rows][cols]){
    int sum = 0;
    if (rows == cols){
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
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

int upperTriang(int rows, int cols, int matrix[rows][cols]){
    int sum = 0;
    if (rows == cols){
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
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

int lowerTriang(int rows, int cols, int matrix[rows][cols]){
    int sum = 0;
    if (rows == cols){
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (j <= i){
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

void printTranspose(int rows, int cols, int matrix[rows][cols]){
    for (int j = 0; j < cols; j++){
        for (int i = 0; i < rows; i++){
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}


int main(){
    int matrix[3][3];
    int sum;

    printf("Input a 3x3 matrix by rows:\n");
    scanMatrix(3, 3, matrix);

    printf("\nInputted matrix:\n");
    printMatrix(3, 3, matrix);

    printf("\n\nThe diagonal of that matrix is:\n");
    sum = diagonal(3, 3, matrix);
    printf("The sum of its elements is %d\n", sum);

    printf("\n\nThe upper triangular of that matrix is:\n");
    sum = upperTriang(3, 3, matrix);
    printf("The sum of its elements is %d\n", sum);

    printf("\n\nThe lower triangular of that matrix is:\n");
    sum = lowerTriang(3, 3, matrix);
    printf("The sum of its elements is %d\n", sum);

    printf("\n\nThe transpose of that matrix is:\n");
    printTranspose(3, 3, matrix);

    return 0;
}
