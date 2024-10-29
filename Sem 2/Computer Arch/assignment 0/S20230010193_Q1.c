#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[10];
    int number;

    printf("Enter a number: ");
    gets(input);  // This line may be causing the segmentation fault

    number = atoi(input);

    printf("Converted number: %d\n", number);

    return 0;
}
