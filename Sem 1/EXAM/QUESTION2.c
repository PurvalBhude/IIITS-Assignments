#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//ptr is pointer to start of array and n is size of array and num is number whose size we have to find 
int index(double *ptr,int n, int num){
    for(int i=0;i<n;i++){
        if(ptr[i] == num){
            return i;
        }
    }
}

double greatest(double *ptr,int n){
    double great = ptr[0];
    for(int i=1;i<n;i++){
        if(ptr[i]>great){
            great = ptr[i];
        }
    }
    return great;
}

int secondlargeindex(double *ptr,int n){
    double great = greatest(ptr,n);
    int great_index = index(ptr,n,great);

    int count = -1;
    double current = 0;
    int k = n-1;
    for(int i=0;i<n;i++){
        if(i == great_index){
            if(i==k){
                break;
            }
            continue;
        }
        if(ptr[i]>current && ptr[i]<great){
            current = ptr[i];
            count = i;
        }
    }
    return count;
}

int main(){
    int n;
    printf("enter size of array: ");
    scanf("%d",&n);

    double* ptr;
    ptr = (double *) calloc(n,sizeof(double));

    printf("enter the array \n");
    for(int i=0;i<n;i++){
        scanf("%lf",&ptr[i]);
    }

    printf("greatest element = %.1lf\n",greatest(ptr,n));
    printf("index of second greatest = %d",secondlargeindex(ptr,n));

}