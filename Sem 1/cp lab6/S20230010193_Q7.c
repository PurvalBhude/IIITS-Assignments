#include<stdio.h>

int main(){
    int n;
    printf("Enter Size of Array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int odd = 0;
    int even = 0;
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            even++;
        }
        else{
            odd++;
        }
    }
    printf("Number of Odd: %d",odd);
    printf("\n");
    printf("Number of Even: %d",even);
}