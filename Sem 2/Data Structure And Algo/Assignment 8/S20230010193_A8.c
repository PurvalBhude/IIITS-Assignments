#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to push data into a circular queue
void push(int *queue, int size, int *front, int *rear, int data)
{
    int temp = ((*rear) + 1) % size;
    if ((*front) == temp)
    {
        printf("queue is full, push operation not done\n");
        return;
    }
    *rear = temp;
    queue[(*rear)] = data;
    printf("%d is pushed in queue\n", data);
    printf("after pushing front = %d , rear = %d\n", *front, *rear);
}

// Function to pop data from a circular queue
void pop(int *queue, int size, int *front, int *rear)
{
    printf("%d is pop from queue\n", queue[(*front)]);
    *front = (*front + 1) % size;
    printf("after pop front = %d , rear = %d\n", *front, *rear);
}

// Function to print all elements in a circular queue
void printqueue(int *queue, int size, int front, int rear)
{
    printf("printing elements in queue: ");
    int i = front;
    do
    {
        printf("%d ", queue[i % size]);
        i++;
    } while ((i % size) != rear);
    printf("%d", queue[i % size]);
    printf("\n");
}

// Function to check if a sequence of 1s in an array is undivided
int undividedblock(int *arr, int n)
{
    // Number of ones
    int one = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            one++;
        }
    }
    if (one == 0)
    {
        printf("ans:0\n");
        return 0;
    }
    // Checking first occurrence of 1
    int first = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            first = i;
            break;
        }
    }
    // Checking if the sequence of 1s is continuous
    for (int i = first; i < (first + one); i++)
    {
        if (arr[i] == 0)
        {
            printf("ans:0");
            return 0;
        }
    }
    printf("ans:1");
    return 1;
}

// Function to rotate an array 'times' number of times
int rotate(int *arr, int n, int times)
{
    for (int i = 1; i <= times; i++)
    {
        int temp = arr[n - 1];
        for (int j = n - 1; j >= 0; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[0] = temp;
    }
}

// Function to perform binary search on a rotated array
int binarysearch(int *arr, int n, int key)
{
    // Search for rotation
    int times;
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            times = n - i;
            break;
        }
    }
    rotate(arr, n, times);
    // Binary search
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] > key)
        {
            high = mid - 1;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            printf("position of searchkey is %d\n", (mid+times+1)%n);
            return mid;
        }
    }
    printf("search key not found\n");
    return -1;
}

int main()
{
    int result;
    printf("Enter the Question number that you have to run: ");
    scanf("%d", &result);
    if (result == 1)
    {
        // Question 1
        int size = 5;
        int queue[size];
        int front = 2;
        int rear = 4;
        queue[2] = 10;
        queue[3] = 20;
        queue[4] = 40;
        push(queue, size, &front, &rear, 50);
        push(queue, size, &front, &rear, 60);
        printf("if we try pushing 30\n");
        push(queue, size, &front, &rear, 30);
        pop(queue, size, &front, &rear);
        pop(queue, size, &front, &rear);
        push(queue, size, &front, &rear, 70);
        push(queue, size, &front, &rear, 80);
        push(queue, size, &front, &rear, 90);
        printqueue(queue, size, front, rear);
    }
    if (result == 2)
    {
        // question 2
        int n;
        printf("Enter size of array: ");
        scanf("%d", &n);
        int arr[n];
        printf("Enter array elements: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        undividedblock(arr, n);
    }
    if (result == 3)
    {
        // Question 3
        int n;
        printf("Enter size of array: ");
        scanf("%d", &n);
        int arr[n];
        printf("Enter array elements: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        int searchkey;
        printf("enter the element which has to be search: ");
        scanf("%d", &searchkey);
        binarysearch(arr, n, searchkey);
    }
    if (result == 4)
    {
        // Qestion 4
        int n;
        printf("Enter the size of the array: ");
        scanf("%d", &n);

        int arr[n];
        printf("Enter the elements: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        int hash[9] = {-1};

        for (int i = 0; i < n; i++)
        {
            int done = 0;
            int data = arr[i] % 9;
            while (done == 0)
            {
                if (hash[data] == 0)
                {
                    hash[data] = arr[i];
                    done = 1;
                }
                else
                {
                    printf("Collision occurred for %d at %d\n", arr[i], data);
                    data = (data + 1) % 9;
                }
            }
        }

        printf("Final table values:\n");
        for (int i = 0; i < 9; i++)
        {
            printf("hash[%d] = %d\n", i, hash[i]);
        }
    }
    return 0;
}