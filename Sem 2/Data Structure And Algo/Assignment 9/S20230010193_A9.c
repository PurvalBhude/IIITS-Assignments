#include <stdio.h>
#include <stdlib.h>

void insertlinear(int *arr, int data, int size)
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
        position = ((data % size) + i) % size;
    }
    printf("%d got inserted and %d collision happened during insertion\n", data, i);
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
    printf("%d got inserted and %d collision happened during insertion\n", data, i);
}

void printtable(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void check(int *arr1, int *arr2, int size)
{
    int *hash1 = (int *)calloc(10, sizeof(int));
    int *hash2 = (int *)calloc(10, sizeof(int));
    for (int i = 0; i < size; i++)
    {
        insert(hash1, arr1[i], 10);
        insert(hash2, arr2[i], 10);
    }
    printf("hash table 1 : ");
    printtable(hash1, 10);

    printf("\nhash table 2 : ");
    printtable(hash2, 10);
    for (int i = 0; i < 10; i++)
    {
        if (hash1[i] != hash2[i])
        {
            printf("\nFalse\n");
            return;
        }
    }
    printf("\nTrue\n");
}

int main()
{
    printf("enter the question which you have to run: ");
    int question;
    scanf("%d", &question);
    if (question == 1)
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
            insertlinear(arr, data, size);
            numberofzeros = countzero(arr, size);
            if ((1 - (numberofzeros / size)) >= 0.8)
            {
                size = size * 2;
                arr = (int *)realloc(arr, size * sizeof(int));
            }
        }
    }
    else if (question == 2)
    {
        // Question 2
        printf("enter size of input array: ");
        int size;
        scanf("%d", &size);
        printf("enter first array: ");
        int arr1[size];
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &arr1[i]);
        }
        printf("enter second array: ");
        int arr2[size];
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &arr2[i]);
        }
        check(arr1, arr2, size);
    }
    else if (question == 3)
    {
        // Question 3
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
    else
    {
        printf("Question not found!!!");
    }
}