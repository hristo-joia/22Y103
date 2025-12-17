// Άσκηση 2
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1
#define MAX_NAME 20

void scanStr(char* str, int limit) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
    fgets(str, limit, stdin);
    return;
}

typedef struct employee {
    char name[MAX_NAME];
    char surname[MAX_NAME];
    float salary;
    int sales;
    int hiringYear;
} Employee;

void scanEmployees(Employee list[], int count) {
    for (int i = 0; i < count; i++) {
        printf("\nScanning employee #%d\n", i + 1);

        printf("Enter the employee's name: ");
        scanStr(list[i].name, MAX_NAME);
        list[i].name[strcspn(list[i].name, "\n")] = '\0';

        printf("Enter the employee's first surname: ");
        scanStr(list[i].surname, MAX_NAME);
        list[i].surname[strcspn(list[i].surname, "\n")] = '\0';

        printf("Enter the employee's salary: ");
        scanf("%f", &list[i].salary);

        printf("Enter the employee's number of sales: ");
        scanf("%d", &list[i].sales);

        printf("Enter the employee's hiring year: ");
        scanf("%d", &list[i].hiringYear);

        printf("%s %s %g %d %d", list[i].name, list[i].surname, list[i].salary, list[i].sales, list[i].hiringYear);
    }
    return;
}

void maxSalary(Employee list[], int count) {
    float maxSal = FLT_MIN;
    int maxID[N] = {0};
    maxID[0] = -1;  // το -1 αναδεικνύει το τέλος του πίνακα
    int j = 0;      // το j αναδεικνύει το τέλος του πίνακα

    for (int i = 0; i < count; i++) {
        if (list[i].salary > maxSal) {
            maxSal = list[i].salary;
            maxID[0] = i;
            // maxID[1] = -1;
            j = 0;  // μηδενισμός του πίνακα
        }
        if (list[i].salary == maxSal) {
            maxID[j] = i;
            j++;
        }
    }
    printf("The employees with the biggest salary are:\n");
    for (int i = 0; i < j; i++) {
        printf("%s %s\n", list[i].name, list[i].surname);
    }
    printf("Earning %g", maxSal);
    return;
}

int main() {
    Employee employeeList[N];

    printf("Input the data of %d employees:\n", N);
    scanEmployees(employeeList, N);

    return 0;
}
