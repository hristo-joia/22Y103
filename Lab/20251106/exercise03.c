#include <stdio.h>
#include <math.h>
//Άσκηση 3
//https://en.wikipedia.org/wiki/Doubling_time
int main() {
    long population;
    printf("Give city population: ");
    scanf("%d", &population);

    float growthRate;
    printf("Give annual population growth rate as a percentage: ");
    scanf("%f", growthRate);

    float doublingTime = log(2)/log(1+growthRate/100);
    printf("The population will double in %f years", doublingTime);

    return 0;
}
