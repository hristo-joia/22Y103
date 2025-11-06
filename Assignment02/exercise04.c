#include <stdio.h>
//Άσκηση 4

int main() {
    int n;
    do {
        printf("Give an integer (1-10): ");
        scanf("%d", &n);
    } while(n <=0 || n > 10);

    int sum = 0;
    for (int i=1; i<=n; i++){
        sum += 9*i*i; // (3n)^2 = 9n^2 = 9*n*n
    }
    printf("%d", sum);
}
