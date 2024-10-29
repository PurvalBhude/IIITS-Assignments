#include <stdio.h>

int main() {
    int k, i;

    printf("Enter the number of input to be taken ");
    scanf("%d", &k);

    char arr[k]; 

    for (i = 0; i < k; i++) {
        printf("Enter number %d ", i + 1);
        scanf("%c", &arr[i]); 
    }

    printf("the taken input are ");

    for (i = 0; i < k; i++) {
        printf("%c ", arr[i]); 

    printf("\n");
    }
}
