#include <stdio.h>
// Άσκηση 4

int sum3n2(int n){
    // Υπολόγισε την παράσταση 3²+6²+9²+...+(3N)²
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += 9 * i * i;  // (3n)² = 9n² = 9*n*n
    return sum;
}


int main() {
    int n;
    do {
        printf("Give an integer (1-10): ");
        scanf("%d", &n);
    } while (n < 1 || n > 10);  // επικύρωση εισόδου

    int sum;
    sum = sum3n2(n);

    printf("%d", sum);
}
