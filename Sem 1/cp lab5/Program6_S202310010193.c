#include <stdio.h>
int main() {
    int n;
    printf("Enter Number: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("Row %d:",i);
        for(int j=2;j<=12;j=j+2){
            printf("%d",j);
            printf(" ");
        }
        printf("\n");
    }
}