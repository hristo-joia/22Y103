#include <stdio.h>
//Άσκηση 6

int main() {
    int n;
    printf("Give how many numbers to scan: ");
    scanf("%d", &n);

    int numbers[n];
    printf("Give %d numbers to scan: ", n);
    for (int i=0; i<n; i++){
        scanf("%d", &numbers[i]);
    }
    int maxNum = 0;
    int maxCount = 0;
    for (int i=0; i<n; i++){
        int count = 1;
        for (int j=i+1; j<n; j++){
            if (numbers[i] == numbers[j]) count++;
        }
        if (count > maxCount) {
            maxNum = numbers[i];
            maxCount = count;
        }
    }
    printf("The number %d appeared the most, with %d occurances.\n", maxNum, maxCount);
    return 0;
}
