/*
Name: Purval Madhukar Bhude
Roll No. S20230010193
Assignment 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int *array, int start, int middle, int end)
{
    int len1 = middle - start + 1;
    int len2 = end - middle;

    int leftArr[len1], rightArr[len2];

    for (int x = 0; x < len1; x++)
        leftArr[x] = array[start + x];
    for (int y = 0; y < len2; y++)
        rightArr[y] = array[middle + 1 + y];

    int index1 = 0, index2 = 0;
    int currentIndex = start;
    while (index1 < len1 && index2 < len2)
    {
        if (leftArr[index1] <= rightArr[index2])
        {
            array[currentIndex] = leftArr[index1];
            index1++;
        }
        else
        {
            array[currentIndex] = rightArr[index2];
            index2++;
        }
        currentIndex++;
    }
    while (index1 < len1)
    {
        array[currentIndex] = leftArr[index1];
        index1++;
        currentIndex++;
    }
    while (index2 < len2)
    {
        array[currentIndex] = rightArr[index2];
        index2++;
        currentIndex++;
    }
}

void divideAndConquer(int *array, int start, int end)
{
    if (start >= end)
        return;

    int middle = start + (end - start) / 2;
    divideAndConquer(array, start, middle);
    divideAndConquer(array, middle + 1, end);
    merge(array, start, middle, end);
}

void mergesort(int *arr, int n)
{
    divideAndConquer(arr, 0, n - 1);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int *arr, int low, int high)
{

    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void QuickSort(int *arr, int n)
{
    quickSort(arr, 0, n - 1);
}

int randpartition(int *arr, int low, int high)
{
    int random = (rand() % (high - low + 1)) + low;
    int pivot = arr[random];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void randquickSort(int *arr, int low, int high)
{

    if (low < high)
    {
        int pi = randpartition(arr, low, high);
        randquickSort(arr, low, pi - 1);
        randquickSort(arr, pi + 1, high);
    }
}

void random_QuickSort(int *arr, int n)
{
    randquickSort(arr, 0, n - 1);
}

int main()
{
    printf("enter the question you want to run: ");
    int q;
    scanf("%d", &q);
    // for Question 1
    if (q == 1)
    {
        int n;
        printf("enter the size of array: ");
        scanf("%d", &n);
        int arr[n];
        printf("enter element in array: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        mergesort(arr, n);
        printf("sorted array: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    // for Question 2
    else if (q == 2)
    {
        int n;
        printf("enter the size of array: ");
        scanf("%d", &n);
        int arr[n];
        printf("enter element in array: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        QuickSort(arr, n);
        printf("sorted array: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    // for Question 3
    else if (q == 3)
    {
        int n;
        printf("enter the size of array: ");
        scanf("%d", &n);
        int arr[n];
        printf("enter element in array: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        random_QuickSort(arr, n);
        printf("sorted array: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    // for Question 4
    else if (q == 4)
    {
        printf("Enter the numbers that you have to multiply \n");
        char num1[100], num2[100];

        printf("Number 1: ");
        scanf("%s", num1);
        printf("Number 2: ");
        scanf("%s", num2);

        int n1 = 0, n2 = 0;
        for (int i = 0; num1[i] != '\0'; i++)
        {
            n1 *= 10;
            n1 += (num1[i] - '0');
        }
        for (int i = 0; num2[i] != '\0'; i++)
        {
            n2 *= 10;
            n2 += (num2[i] - '0');
        }

        int ans = n1 * n2;
        int temp = ans;
        int size = 0;
        while (temp != 0)
        {
            temp /= 10;
            size++;
        }

        char output[size + 1];
        output[size] = '\0';

        for (int i = size - 1; i >= 0; i--)
        {
            output[i] = (ans % 10) + '0';
            ans /= 10;
        }

        printf("Answer is %s\n", output);
    }
    // for Question 5
    else if (q == 5)
    {
        int n;
        printf("enter value of n to make two n*n matrix: ");
        scanf("%d", &n);
        int a[n][n];
        int b[n][n];

        printf("enter a matrix A\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("A[%d][%d]: ", i, j);
                scanf("%d", &a[i][j]);
            }
        }

        printf("enter a matrix B\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("B[%d][%d]: ", i, j);
                scanf("%d", &b[i][j]);
            }
        }

        int result[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                result[i][j] = 0;
                for (int k = 0; k < n; k++)
                {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        printf("\n");
        printf("Result: \n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    }
    // for Question else case
    else
    {
        printf("Question not found !!!");
    }
}
