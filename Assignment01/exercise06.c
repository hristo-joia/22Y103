#include <stdio.h>

// Άσκηση 6

int main() {
    // οι έξι οκτάδες της διεύθυνσης MAC
    int oct[6];

    printf("Give a MAC address in x:x:x:x:x:x format: ");
    scanf("%x:%x:%x:%x:%x:%x", &oct[0], &oct[1], &oct[2], &oct[3], &oct[4],
          &oct[5]);  // %x για ανάγνωση δεκαεξαδικού

    // η MAC διεύθυνση με όλες τις οκτάδες 0xFF είναι broadcast
    if (oct[0] == 0xFF && oct[1] == 0xFF && oct[2] == 0xFF && oct[3] == 0xFF &&
        oct[4] == 0xFF && oct[5] == 0xFF)  // όλες οι οκτάδες είναι 0xFF
        printf("This is a broadcast MAC address.\n");

    // οι άρτιες οκτάδες oct[0] είναι unicast
    else if (oct[0] % 2 == 0)  // άρτιος % 2 == 0
        printf("This is a unicast MAC address.\n");

    // οι περιττές οκτάδες oct[0] είναι multicast
    else
        printf("This is a multicast MAC address.\n");

    return 0;
}
