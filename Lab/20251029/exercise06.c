#include <stdio.h>

// Άσκηση 6

int main() {
    // οι έξι οκτάδες της διεύθυνσης MAC
    int oct1, oct2, oct3, oct4, oct5, oct6;

    printf("Give a MAC address in xx:xx:xx:xx:xx:xx format: ");
    scanf("%x:%x:%x:%x:%x:%x", &oct1, &oct2, &oct3, &oct4, &oct5, &oct6);
    // %x για ανάγνωση δεκαεξαδικού

    // η MAC διεύθυνση με όλες τις οκτάδες 0xFF είναι broadcast
    if (oct1 == 0xFF && oct2 == 0xFF && oct3 == 0xFF && oct4 == 0xFF &&
        oct5 == 0xFF && oct6 == 0xFF)  // όλες οι οκτάδες είναι FF
        printf("This is a broadcast MAC address.\n");

    // οι άρτιες οκτάδες oct1 είναι unicast
    else if (oct1 % 2 == 0)  // άρτιος % 2 == 0
        printf("This is a unicast MAC address.\n");

    // οι περιττές οκτάδες oct1 είναι multicast
    else
        printf("This is a multicast MAC address.\n");

    return 0;
}
