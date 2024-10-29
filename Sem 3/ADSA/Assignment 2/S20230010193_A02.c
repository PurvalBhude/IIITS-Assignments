/*
Name: Purval Madhukar Bhude
Roll No. S20230010193
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int swapbubble(int arr[], int n)
{
    int temp;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;
            }
        }
    }
    return count;
}

int selectionsort(int *arr, int n)
{
    int min, index, temp;
    for (int i = 0; i < n - 1; i++)
    {
        min = 200;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                index = j;
            }
        }
        temp = arr[index];
        arr[index] = arr[i];
        arr[i] = temp;
    }
}

void insertionsort(int *arr, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n - 1; j++)
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

void insert(int heap[], int *n, int value)
{
    int i = (*n)++;
    heap[i] = value;

    while (i != 0 && heap[(i - 1) / 2] > heap[i])
    {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void heapifyDown(int heap[], int n, int i)
{
    int sma = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[sma])
        sma = left;

    if (right < n && heap[right] < heap[sma])
        sma = right;

    if (sma != i)
    {
        int temp = heap[i];
        heap[i] = heap[sma];
        heap[sma] = temp;
        heapifyDown(heap, n, sma);
    }
}

void deleteMin(int heap[], int *n)
{
    if (*n <= 0)
    {
        printf("Heap is empty!\n");
        return;
    }

    heap[0] = heap[--(*n)];

    heapifyDown(heap, *n, 0);
}

int main()
{
    printf("Enter which question you want to run: ");
    int question;
    scanf("%d", &question);
    if (question == 1)
    {
        printf("insertion sort is the best algorithm for this problem\n");
        int n;
        printf("enter the size of array: ");
        scanf("%d", &n);
        int array[n];
        printf("enter the array: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &array[i]);
        }
        printf("sort array: ");
        insertionsort(array, n);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", array[i]);
        }
    }

    else if (question == 2)
    {
        int n;
        printf("Enter size of array: ");
        scanf("%d", &n);
        int arr[n];
        printf("Enter array: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        printf("number of swaps: %d", swapbubble(arr, n));
    }

    else if (question == 3)
    {
        int n;
        printf("Enter the number of elements you want to heap: ");
        scanf("%d", &n);
        int heap[n];
        int ele;
        int current_size = 0;
        printf("Enter elements: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &ele);
            insert(heap, &current_size, ele);
        }

        printf("Created min heap: ");
        for (int i = 0; i < current_size; i++)
        {
            printf("%d ", heap[i]);
        }
        printf("\n");

        int sel;
        while (current_size != 1)
        {
            printf("Delete minimum (1 for yes | 0 for no): ");
            scanf("%d", &sel);
            if (sel == 0)
            {
                break;
            }
            else
            {
                deleteMin(heap, &current_size);
                printf("After deletion of minimum: ");
                for (int i = 0; i < current_size; i++)
                {
                    printf("%d ", heap[i]);
                }
                printf("\n");
            }
        }
    }

    else if (question == 4)
    {
        int n;
        printf("enter the size of stack: ");
        scanf("%d", &n);
        printf("Enter the element in stack: ");
        int stack[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &stack[i]);
        }
        int k, max;
        printf("enter the k (number of element to be removed)");
        scanf("%d", &k);
        int sum = 0;

        for (int i = 0; i < k; i++)
        {
            sum += stack[i];
        }
        max = sum;

        for (int i = 1; i <= k; i++)
        {
            sum = sum - stack[k - i] + stack[n - i];
            if (sum > max)
            {
                max = sum;
            }
        }
        printf("maximum sum possible is %d", max);
    }

    else if (question == 5)
    {
        int n;
        printf("Enter number of player participated in marathon (n): ");
        scanf("%d", &n);
        int age[n];
        printf("Enter the age array: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &age[i]);
        }
        selectionsort(age, n);
        printf("Age of 3 youngest player are %d %d %d \n", age[0], age[1], age[2]);
        printf("Age of 3 older player are %d %d %d", age[n - 1], age[n - 2], age[n - 3]);
    }

    else
    {
        printf("Question not vaild!!! Try Again!!!");
    }
}