#include <stdio.h>

void scanTable(int rows, int cols, int table[rows][cols]){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            scanf("%d", &table[i][j]);
        }
    }
    return;
}

void printTable(int rows, int cols, int table[rows][cols]){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("%d\t", table[i][j]);
        }
        printf("\n");
    }
}

void deleteCross(int rows, int cols, int tablein[rows][cols], int tableout[rows-1][cols-1],int del){
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++){
            if (i<del){
                if (j<del){
                tableout[i][j] = tablein[i][j];
                } else {
                    tableout[i][j] = tablein[i][j+1];
                }
            } else {
                if (j<del){
                    tableout[i][j] = tablein[i+1][j];
                } else {
                    tableout[i][j] = tablein[i+1][j+1];
                }
            }
        }
    }
    return;
}

int main(){
    int table1[5][5]={{11, 12, 13, 14, 15}, {21, 22, 23, 24, 25},{31, 32, 33, 34, 35}, {41, 42, 43, 44, 45}, {51, 52, 53, 54, 55}};
    int table2[4][4];

    printf("Input a 5x5 table by rows:\n");

    // scanTable(5, 5, table1);

    printf("Inputted table:\n");
    printTable(5, 5, table1);

    printf("Give a number to delete that row and column [1-5]: ");

    int x;

    do
        scanf("%d", &x);
    while(x<1 || x>5);
    x--;

    deleteCross(5, 5, table1, table2, x);

    printTable(4, 4, table2);
    return 0;

}
