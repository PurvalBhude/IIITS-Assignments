#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void addNode(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

struct Node* findLastNode(struct Node* head) {
    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        current = current->next;
    }
    return current;
}

struct Node* appendNode(struct Node* head, struct Node* tail, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    return tail;
}

struct Node* mergeLists(struct Node* head1, struct Node* tail1, struct Node* head2, struct Node* tail2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    tail1->next = head2;
    return tail2;
}

struct Node* partition(struct Node* start, struct Node* end) {
    struct Node* pivot = start;
    struct Node* front = start;
    int temp = 0;
    while (front != NULL && front != end) {
        if (front->data < end->data) {
            pivot = start;
            temp = start->data;
            start->data = front->data;
            front->data = temp;
            start = start->next;
        }
        front = front->next;
    }
    temp = start->data;
    start->data = end->data;
    end->data = temp;
    return pivot;
}

void QuickSort(struct Node* start, struct Node* end) {
    if (start == end || start == NULL || end == NULL) {
        return;
    }
    struct Node* pivotNode = partition(start, end);
    if (pivotNode != NULL && pivotNode->next != NULL) {
        QuickSort(pivotNode->next, end);
    }
    if (pivotNode != NULL && start != pivotNode) {
        QuickSort(start, pivotNode);
    }
}

int main() {
    struct Node* head = NULL;
    int value;

    int size;
    printf("Enter the number of elements to be entered: ");
    scanf("%d", &size);

    // Input loop
    printf("Enter values:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &value);
        addNode(&head, value);
    }

    printf("Before Sorting:");
    struct Node* current = head;
    printf("\nLinked List:");
    while (current != NULL) {
        printf(" %d", current->data);
        current = current->next;
    }

    struct Node* tail = findLastNode(head);
    QuickSort(head, tail);

    printf("\nAfter Sorting:");
    current = head;
    printf("\nLinked List:");
    while (current != NULL) {
        printf(" %d", current->data);
        current = current->next;
    }

    return 0;
}