#include <stdio.h>
#include <stdlib.h>

void printtable(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void insert(int *arr, int data, int size)
{
    int position = data % 10;
    int i = 0;
    while (1)
    {
        if (arr[position] == 0)
        {
            arr[position] = data;
            break;
        }
        i++;
        position = ((data % 10) + i) % 10;
    }
}

int countzero(int *arr, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    // Question 1
    int size = 5;
    int *arr = (int *)calloc(size, sizeof(int));
    int numberofzeros;
    printf("insert elements (enter 0 to exit the program): ");
    int data;
    while (1)
    {
        scanf("%d", &data);
        if (data == 0)
        {
            printf("insertion operation ended\n");
            printf("printing hash table\n");
            printtable(arr, size);
            break;
        }
        insert(arr, data, size);
        numberofzeros = countzero(arr, size);
        if ((1 - (numberofzeros / size)) >= 0.8)
        {
            size = size * 2;
            arr = (int *)realloc(arr, size * sizeof(int));
        }
    }
}