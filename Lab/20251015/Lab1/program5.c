#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1; //1st point
    double x2, y2; //2nd point
    double result;

    printf("Input first point: ");
    scanf("%lf%lf", &x1, &y1);

    printf("Input second point: ");
    scanf("%lf%lf", &x2, &y2);

    result = (x1-x2)*(x1-x2) + (y1 - y2)*(y1-y2);
    result = sqrt(result);

    //printf("The distance between points (%lf, %lf) and (%lf, %lf) is %lf", x1, y1, x2, y2, result);
    printf("The distance is %.4f", result);
    return 0;
}
