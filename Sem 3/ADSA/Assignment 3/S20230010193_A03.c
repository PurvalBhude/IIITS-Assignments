/*
Name : Purval Madhukar Bhude
Roll No. S20230010193
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int BS(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] >= arr[low])
        {

            if (key >= arr[low] && key < arr[mid])
                high = mid - 1;

            else
                low = mid + 1;
        }
        else
        {
            if (key > arr[mid] && key <= arr[high])
                low = mid + 1;

            else
                high = mid - 1;
        }
    }
}

void bubblesort(int *arr, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionsort(int *arr, int n)
{
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void MaxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        MaxHeapify(arr, n, largest);
    }
}

void BuildMaxHeap(int arr[], int n)
{

    int startIdx = (n / 2) - 1;
    for (int i = startIdx; i >= 0; i--)
    {
        MaxHeapify(arr, n, i);
    }
}

void HeapSort(int arr[], int n)
{

    BuildMaxHeap(arr, n);
    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        MaxHeapify(arr, i, 0);
    }
}

int main()
{
    printf("Enter the question you want to run: ");
    int option;
    scanf("%d", &option);
    if (option == 1)
    {
        printf("Enter Size of array: ");
        int n;
        scanf("%d", &n);
        printf("Enter array: ");
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        HeapSort(arr, n);
        printf("printing sorted array: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    else if (option == 2)
    {
        int stack[10];
        int queue[10];
        int top = 0;
        int front = 0;
        int bottom = 0;
        printf("Start entering people\n");
        int input = 1, id;
        while (input != 0)
        {
            printf("1 for priority, 2 for normal, 0 to exit: ");
            scanf("%d", &input);
            if (input == 0)
            {
                break;
            }
            printf("Enter customer id: ");
            scanf("%d", &id);
            if (input == 1)
            {
                stack[top] = id;
                top++;
            }
            else if (input == 2)
            {
                queue[bottom] = id;
                bottom++;
            }
            else
            {
                break;
            }
        }
        printf("Printing line: ");
        printf("Start <--");
        for (int i = 0; i < top; i++)
        {
            printf("ID %d <-- ", stack[i]);
        }

        for (int i = front; i < bottom; i++)
        {
            printf("ID %d <-- ", queue[i]);
        }
        printf("End");
    }
    else if (option == 3)
    {
        printf("Enter Size of array: ");
        int n;
        scanf("%d", &n);
        printf("Enter sorted and rotated array: ");
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        int key;
        printf("Enter the number that you want to search: ");
        scanf("%d", &key);
        printf("%d", BS(arr, n, key));
    }
    else if (option == 4)
    {
    }
    else if (option == 5)
    {
        printf("Enter Size of array: ");
        int n;
        scanf("%d", &n);
        printf("Enter array: ");
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        int *arr1 = (int *)malloc(n * sizeof(int));
        int *arr2 = (int *)malloc(n * sizeof(int));
        memcpy(arr1, arr, n * sizeof(int));
        memcpy(arr2, arr, n * sizeof(int));

        clock_t time1 = clock();
        bubblesort(arr1, n);
        time1 = clock() - time1;
        printf("time taken in bubble sort: %f seconds\n", ((float)time1) / CLOCKS_PER_SEC);

        clock_t time2 = clock();
        insertionsort(arr2, n);
        time2 = clock() - time2;
        printf("time taken in insertion sort: %f seconds\n", (((float)time2) / CLOCKS_PER_SEC));

        printf("minimum temp: %d\n", arr1[0]);
        printf("maximum temp: %d\n", arr1[n - 1]);

        if (n % 2 == 0)
        {
            printf("median: %f\n", (arr1[n / 2 - 1] + arr1[n / 2]) / 2.0);
        }
        else
        {
            printf("median: %d\n", arr1[n / 2]);
        }

        printf("range in temperature: %d \n", arr1[n - 1] - arr1[0]);

        free(arr1);
        free(arr2);
    }
    else
    {
        printf("Question not mentioned");
    }
}