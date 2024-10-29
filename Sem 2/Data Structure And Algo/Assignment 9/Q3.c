#include <stdio.h>
#include <stdlib.h>

void insertquadratic(int *arr, int data, int size)
{
    int position = data % size;
    int i = 0;
    while (1)
    {
        if (arr[position] == 0)
        {
            arr[position] = data;
            break;
        }
        i++;
        position = ((data % size) + (i * i)) % size;
    }
    printf("%d collision\n", data, i);
}

void printtable(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main(){
    printf("Enter size of hash table: ");
        int size;
        scanf("%d", &size);
        printf("Enter number of element you have to enter: ");
        int element;
        scanf("%d", &element);
        int *arr = (int *)calloc(size, sizeof(int));
        printf("insert elements: ");
        int data;
        for (int i = 0; i < element; i++)
        {
            scanf("%d", &data);
            insertquadratic(arr, data, size);
        }
        printtable(arr, size);
}