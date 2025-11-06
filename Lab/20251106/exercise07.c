#include <stdio.h>
//Άσκηση 7

int sumOf(int N){
    int sum = 0;
    for (int i=0; i<=N; i++) sum += i;
    return sum;
}
int main() {
    int N;
    do{
        printf("Give an integer: ");
        scanf("%d", &N);
        if (N<0){
            printf("Cannot execute for a negative number.\n");
        }
    } while (N<0);

    printf("The first %d natural numbers are: ", N);
    for (int i=0; i<N; i++){
        printf("%d ", i);
    }

    int sum = sumOf(N);
    printf("\nThe sum of them is %d", sum);

    printf("\nTheir average is %.1f", (float) sum/N);

    printf("\nTheir squares are: ");
    for (int i=0; i<N; i++){
        printf("%d ", i*i);
    }

}
