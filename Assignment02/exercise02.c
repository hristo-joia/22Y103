#include <stdio.h>
//Άσκηση 2

int main() {
    //char character;
    for (int i=0; i<=126-48; i++){
        printf("%c (%d)\t", i+48, i+48);
        if ((i+1) % 10 == 0) printf("\n");
    }
    return 0;
}
