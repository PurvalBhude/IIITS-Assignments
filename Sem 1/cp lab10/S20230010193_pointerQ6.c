#include <stdio.h>

void intersection(int* arr1, int size_arr1, int* arr2, int size_arr2, int* answer, int* count){
    for(int i=0; i<size_arr1; i++){
        for(int j=0; j<size_arr2; j++){
            if(arr1[i] == arr2[j]){
                answer[*count] = arr1[i];
                (*count)++;
            }
        }
    }
}

int main(){
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size_arr1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {3, 17, 5, 6, 7, 1, 55};
    int size_arr2 = sizeof(arr2) / sizeof(arr2[0]);
    int answer[100];
    int count = 0;
    intersection(arr1, size_arr1, arr2, size_arr2, answer, &count);
    printf("Answer array is of length %d\n", count);
    printf("Answer array: ");
    for(int i=0; i<count; i++){
        printf("%d ", answer[i]);
    }
}
