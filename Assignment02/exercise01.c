#include <stdio.h>
// Άσκηση 1

int main() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 0; j < 100; j += 10) {
            // i = μονάδες, j = δεκάδες
            printf("%d\t", j + i);
        }
        printf("\n");
    }
    return 0;
}
