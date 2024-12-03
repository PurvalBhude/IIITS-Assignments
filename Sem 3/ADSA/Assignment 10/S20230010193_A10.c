/*
* Name : Purval Madhukar Bhude
* Roll No. S20230010193
* Assignment 10 ADSA
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 100

// Structure to represent an edge
struct GraphEdge {
    int start;
    int end;
    int cost;
};

// Structure to represent the MST (for Kruskal's)
struct MSTree {
    struct GraphEdge treeEdges[MAX_EDGES];
    int edgeCount;
    int totalCost;
};

// Structure for disjoint sets (for Kruskal's)
struct Set {
    int leader[MAX_NODES];
    int level[MAX_NODES];
};

// Function prototypes for Prim's Algorithm
int findMinKey(int keys[], bool mstIncluded[], int vertices);
void primMSTree(int adjMatrix[MAX_NODES][MAX_NODES], int vertices);

// Function prototypes for Kruskal's Algorithm
void initializeSet(struct Set* set, int vertices);
int findSet(struct Set* set, int element);
void uniteSets(struct Set* set, int setA, int setB);
int compareGraphEdges(const void* a, const void* b);
struct MSTree kruskalMSTree(struct GraphEdge graphEdges[], int vertices, int edges);

// Prim's Algorithm Implementation
int findMinKey(int keys[], bool mstIncluded[], int vertices) {
    int minimum = INT_MAX, minIndex;
    for (int i = 0; i < vertices; i++) {
        if (!mstIncluded[i] && keys[i] < minimum) {
            minimum = keys[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void primMSTree(int adjMatrix[MAX_NODES][MAX_NODES], int vertices) {
    int parent[MAX_NODES];
    int keys[MAX_NODES];
    bool mstIncluded[MAX_NODES];
    struct GraphEdge mstEdges[MAX_NODES - 1];
    int totalCost = 0;

    // Initialize keys and mstIncluded arrays
    for (int i = 0; i < vertices; i++) {
        keys[i] = INT_MAX;
        mstIncluded[i] = false;
    }
    
    keys[0] = 0;
    parent[0] = -1;
    
    // Find MST by iterating vertices
    for (int count = 0; count < vertices - 1; count++) {
        int u = findMinKey(keys, mstIncluded, vertices);
        mstIncluded[u] = true;

        for (int v = 0; v < vertices; v++) {
            if (adjMatrix[u][v] && !mstIncluded[v] && adjMatrix[u][v] < keys[v]) {
                parent[v] = u;
                keys[v] = adjMatrix[u][v];
            }
        }
    }
    
    // Display MST edges
    printf("\nMST Edges: ");
    for (int i = 1; i < vertices; i++) {
        mstEdges[i-1].start = parent[i] + 1;
        mstEdges[i-1].end = i + 1;
        mstEdges[i-1].cost = adjMatrix[i][parent[i]];
        totalCost += adjMatrix[i][parent[i]];
        printf("(%d,%d)", mstEdges[i-1].start, mstEdges[i-1].end);
        if (i < vertices - 1) printf(", ");
    }
    printf("\nTotal Weight: %d\n", totalCost);
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the
// sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Function to print an array
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Kruskal's Algorithm Implementation
void initializeSet(struct Set* set, int vertices) {
    for (int i = 0; i < vertices; i++) {
        set->leader[i] = i;
        set->level[i] = 0;
    }
}

int findSet(struct Set* set, int element) {
    if (set->leader[element] != element) {
        set->leader[element] = findSet(set, set->leader[element]);
    }
    return set->leader[element];
}

void uniteSets(struct Set* set, int setA, int setB) {
    int rootA = findSet(set, setA);
    int rootB = findSet(set, setB);
    
    if (set->level[rootA] < set->level[rootB]) {
        set->leader[rootA] = rootB;
    }
    else if (set->level[rootA] > set->level[rootB]) {
        set->leader[rootB] = rootA;
    }
    else {
        set->leader[rootB] = rootA;
        set->level[rootA]++;
    }
}

int compareGraphEdges(const void* a, const void* b) {
    return ((struct GraphEdge*)a)->cost - ((struct GraphEdge*)b)->cost;
}

struct MSTree kruskalMSTree(struct GraphEdge graphEdges[], int vertices, int edges) {
    struct MSTree mst = {0};
    struct Set set;
    
    initializeSet(&set, vertices);
    qsort(graphEdges, edges, sizeof(struct GraphEdge), compareGraphEdges);

    for (int i = 0; i < edges && mst.edgeCount < vertices - 1; i++) {
        int srcRoot = findSet(&set, graphEdges[i].start - 1);
        int destRoot = findSet(&set, graphEdges[i].end - 1);
        
        if (srcRoot != destRoot) {
            mst.treeEdges[mst.edgeCount] = graphEdges[i];
            mst.totalCost += graphEdges[i].cost;
            mst.edgeCount++;
            uniteSets(&set, srcRoot, destRoot);
        }
    }
    
    return mst;
}

int main() {
    int choice;
    printf("Choose the algorithm:\n");
    printf("1. Prim's Algorithm\n");
    printf("2. Kruskal's Algorithm\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        // Prim's Algorithm
        int vertices;
        int adjMatrix[MAX_NODES][MAX_NODES] = {0};
        
        printf("\nRunning Prim's Algorithm\n");
        printf("Number of nodes: ");
        scanf("%d", &vertices);
        
        printf("Enter number of edges: ");
        int edges;
        scanf("%d", &edges);
        
        printf("Enter edges (node1, node2, weight):\n");
        for (int i = 0; i < edges; i++) {
            int node1, node2, weight;
            scanf("%d %d %d", &node1, &node2, &weight);
            adjMatrix[node1 - 1][node2 - 1] = weight;
            adjMatrix[node2 - 1][node1 - 1] = weight;
        }
        
        primMSTree(adjMatrix, vertices);
    }
    else if (choice == 2) {
        // Kruskal's Algorithm
        int vertices, edges;
        struct GraphEdge graphEdges[MAX_EDGES];
        
        printf("\nRunning Kruskal's Algorithm\n");
        printf("Number of nodes: ");
        scanf("%d", &vertices);
        
        printf("Enter number of edges: ");
        scanf("%d", &edges);
        
        printf("Enter edges (node1, node2, weight):\n");
        for (int i = 0; i < edges; i++) {
            scanf("%d %d %d", &graphEdges[i].start, &graphEdges[i].end, &graphEdges[i].cost);
        }
        
        struct MSTree mst = kruskalMSTree(graphEdges, vertices, edges);
        
        printf("\nMST Edges: ");
        for (int i = 0; i < mst.edgeCount; i++) {
            printf("(%d,%d)", mst.treeEdges[i].start, mst.treeEdges[i].end);
            if (i < mst.edgeCount - 1) printf(", ");
        }
        printf("\nTotal Weight: %d\n", mst.totalCost);
    }
    else {
        printf("Invalid choice! Please select 1 or 2.\n");
    }
    
    return 0;
}
