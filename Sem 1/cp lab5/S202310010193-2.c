#include <stdio.h>
int main() {
    int n;
    printf("Enter Number: ");
    scanf("%d",&n);
    int i=1;
    while(i<=10){
        int j=n;
        while(j<=n+10){
            printf("%d ",j);
            j++;
        }
        i++;
        printf("\n");
    }
}
