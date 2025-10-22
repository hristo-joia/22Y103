#include <stdio.h>

//Άσκηση 5

int main(){
    char month[3];
    printf("Enter a month in three-letter format (eg. jan): ");
    scanf("%s[3]", &month);

    int mon;
    if (month="jan")
        mon = 1;
    else if (month="feb")
        mon = 2;
    else if (month="mar")
        mon = 3;
    else if (month="apr")
        mon = 4;
    else if (month="may")
        mon = 5;
    else if (month="jun")
        mon = 6;
    else if (month="jul")
        mon = 7;
    else if (month="aug")
        mon = 8;
    else if (month="sep")
        mon = 9;
    else if (month="oct")
        mon = 10;
    else if (month="nov")
        mon = 11;
    else if (month="dec")
        mon = 12;
    else
        printf("There is no such month.");
    }

    printf("%d", mon)
}
