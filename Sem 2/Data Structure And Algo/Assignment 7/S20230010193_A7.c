#include <stdio.h>
#include <stdlib.h>
#define N 100
int queue[N];

struct Node
{
    int data;
    struct Node *next;
};

void returnmax(int queue[], int n, int w)
{
    int max;
    printf("Max are ");
    for (int i = 0; i <= n-w; i++)
    {
        max = queue[i];
        for (int j = i+1; j < i + w; j++)
        {
            if (max < queue[j])
            {
                max = queue[j];
            }
        }
        printf("%d ", max);
    }
}

void printstack(struct Node *head)
{
    struct Node *curr = head;
    printf("Printing stack (used as queue): ");
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

int enqueue(struct Node *head, int data)
{
    // to enqueue directly add;
    struct Node *enque = (struct Node *)malloc(sizeof(struct Node));
    enque->data = data;
    struct Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = enque;
    enque->next = NULL;
    printf("stack(originally queue) after enqueue ");
    printstack(head);
}

int dequeue(struct Node *head)
{
    // to dequeue remove all elements to other stack and then again put them in it
    struct Node *temp = head;
    head = temp->next;
    temp->next = NULL;
    printf("Dequeue element is %d\n", temp->data);
    free(temp);
    printf("stack(originally queue) after dequeue ");
    printstack(head);
}

int main()
{
    int option;
    printf("Choose which question to run: ");
    scanf("%d", &option);

    int n;
    if (option == 1)
    {
        // Question 1
        printf("enter length of queue: ");
        scanf("%d", &n);
        int que[n];
        printf("Enter queue Elements: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &que[i]);
        }
        int w;
        printf("Enter the length of sliding window: ");
        scanf("%d", &w);
        returnmax(que, n, w);
    }

    else if (option == 2)
    {
        // Question 2
        printf("Enter the element you have to put in queue: ");
        scanf("%d", &n);
        struct Node *head = (struct Node *)malloc(sizeof(struct Node));
        printf("enter data: ");
        scanf("%d", &(head->data));
        struct Node *temp;
        for (int i = 1; i < n; i++)
        {
            struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
            scanf("%d", &(curr->data));
            if (i == 1)
            {
                head->next = curr;
            }
            else
            {
                temp->next = curr;
            }
            temp = curr;
        }
        temp->next = NULL;
        printstack(head);
        printf("\n");
        printf("Enter Enqueue Element: ");
        int enque;
        scanf("%d", &enque);
        enqueue(head, enque);
        printf("\n");
        dequeue(head);
    }
    else if (option == 3)
    {
        // Question 3
        printf("Enter Number of elements to enter in queue: ");
        scanf("%d", &n);
        printf("Enter the Queue elements: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &queue[i]);
        }
        int arr1[n / 2];
        int arr2[n / 2];
        if (n % 2 == 0)
        {
            int arr1[n / 2];
            int arr2[n / 2];
        }
        else
        {
            int arr1[(n / 2) + 1];
            int arr2[n / 2];
        }

        // putting in array
        for (int i = 0; i < n; i++)
        {
            if (i < ((n / 2) + 1))
            {
                arr1[i] = queue[i];
            }
            else
            {
                arr2[i - (n / 2) - 1] = queue[i];
            }
        }

        // printing in array one by one
        int a1 = 0;
        int a2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                queue[i] = arr1[a1];
                a1++;
            }
            else
            {
                queue[i] = arr2[a2];
                a2++;
            }
        }

        printf("After doing operation the queue is: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", queue[i]);
        }
    }

    else
    {
        printf("This question does not exist");
    }
    return 0;
}