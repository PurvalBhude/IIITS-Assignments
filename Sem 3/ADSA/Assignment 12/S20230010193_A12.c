/*
 * Name: Purval Madhukar Bhude
 * Roll No. S20230010193
 * ADSA Assignment 12
 */

// importing the libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

// defining constant values
#define MAX_NODES 5
#define SOURCE 0
#define SINK 4

// function to find max function
int max(int i, int j)
{
    //if-else statement
    if (i > j)
    {
        return i;
    }
    return j;
}

// Question 1 functions
// function to run knapsack algorithm
int knapsack(int *values, int *capacity, int n, int m)
{
    //initialize dptable
    int **dpTable = (int **)malloc((n + 1) * sizeof(int *));
    int idx = 0;

    // while loop
    while (idx <= n)
    {
        dpTable[idx] = (int *)malloc((m + 1) * sizeof(int));
        idx++;
    }

    idx = 0;
    // while loop
    while (idx <= n)
    {
        int weightIdx = 0;
        // while loop
        while (weightIdx <= m)
        {
            //if-else statement
            if (idx == 0 || weightIdx == 0)
            {
                dpTable[idx][weightIdx] = 0;
            }
            else if (capacity[idx - 1] <= weightIdx)
            {
                dpTable[idx][weightIdx] = max(
                    values[idx - 1] + dpTable[idx - 1][weightIdx - capacity[idx - 1]],
                    dpTable[idx - 1][weightIdx]);
            }
            else
            {
                dpTable[idx][weightIdx] = dpTable[idx - 1][weightIdx];
            }
            weightIdx++;
        }
        idx++;
    }

    int result = dpTable[n][m];

    //printing dp table which is made above
    printf("-----------------------------------------------------\n");
    printf("DP Table\n");
    printf("-----------------------------------------------------\n");
    printf("  ");
    for (int i = 0; i < m + 1; i++)
    {
        printf("%d  ", i);
    }
    printf("\n");
    for (int i = 0; i < n + 1; i++)
    {
        printf("%d ", i);
        for (int j = 0; j < m + 1; j++)
        {
            printf("%d ", dpTable[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------------------------------\n");

    idx = 0;
    //freeup
    while (idx <= n)
    {
        free(dpTable[idx]);
        idx++;
    }
    // free up
    free(dpTable);
    return result;
}

// Question 1 function to be run in main function
int Question1()
{
    //taking input
    printf("enter the size of values: ");
    int n;
    scanf("%d", &n);
    printf("enter the capacity of knapsack: ");
    int m;
    scanf("%d", &m);

    printf("enter the values array: ");
    int values[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &values[i]);
    }

    printf("enter the weights array: ");
    int weights[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weights[i]);
    }

    //printing output
    int answer = knapsack(values, weights, n, m);
    printf("Maximum value: %d", answer);
}

// Question 2 functions
// Dfs algorithm to find path
bool findPathDFS(int residualNetwork[MAX_NODES][MAX_NODES], bool visited[MAX_NODES],
                 int currentNode, int pathFlow[], int previousNode[])
{

    visited[currentNode] = true;

    //if-else statement
    if (currentNode == SINK)
    {
        return true;
    }
    // for loop
    for (int nextNode = 0; nextNode < MAX_NODES; nextNode++)
    {
        //if-else statement
        if (!visited[nextNode] && residualNetwork[currentNode][nextNode] > 0)
        {
            previousNode[nextNode] = currentNode;

            pathFlow[nextNode] = (pathFlow[currentNode] < residualNetwork[currentNode][nextNode])
                                     ? pathFlow[currentNode]
                                     : residualNetwork[currentNode][nextNode];
        
            //if-else statement
            if (findPathDFS(residualNetwork, visited, nextNode, pathFlow, previousNode))
            {
                return true;
            }
        }
    }
    return false;
}

// merge function
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    // while loop
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // while loop
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    // while loop
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// mergesort function
void mergeSort(int arr[], int l, int r)
{
    //if-else statement
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// function to calculate maximum flow in network
int calculateMaxFlow(int networkCapacity[MAX_NODES][MAX_NODES])
{
    int residualNetwork[MAX_NODES][MAX_NODES];
    int totalFlow = 0;
    int previousNode[MAX_NODES];
    int pathFlow[MAX_NODES];
    bool visited[MAX_NODES];

    // for loop
    for (int i = 0; i < MAX_NODES; i++)
    {
        //for loop
        for (int j = 0; j < MAX_NODES; j++)
        {
            residualNetwork[i][j] = networkCapacity[i][j];
        }
    }
    // while loop
    while (1)
    {
        memset(visited, false, sizeof(visited));
        memset(previousNode, -1, sizeof(previousNode));
        //for loop
        for (int i = 0; i < MAX_NODES; i++)
        {
            pathFlow[i] = INT_MAX;
        }
        //if-else statement
        if (!findPathDFS(residualNetwork, visited, SOURCE, pathFlow, previousNode))
        {
            break;
        }

        int currentFlow = pathFlow[SINK];
        totalFlow += currentFlow;

        int currentNode = SINK;
        // while loop
        while (previousNode[currentNode] != -1)
        {
            int prev = previousNode[currentNode];
            residualNetwork[prev][currentNode] -= currentFlow;
            residualNetwork[currentNode][prev] += currentFlow; // Add reverse edge
            currentNode = prev;
        }
    }

    return totalFlow;
}

// Question 2 function to be run in main function
int Question2()
{
    //assuming input
    int networkCapacity[MAX_NODES][MAX_NODES] = {
        {0, 10, 5, 0, 0},
        {0, 0, 15, 10, 0},
        {0, 0, 0, 5, 10},
        {0, 0, 0, 0, 10},
        {0, 0, 0, 0, 0}};


    // printing output
    printf("Maximum flow in original network: %d\n",
           calculateMaxFlow(networkCapacity));

    networkCapacity[1][3] = 15;

    printf("Maximum flow after increasing A->C capacity to 15: %d\n",
           calculateMaxFlow(networkCapacity));

    /* 1. Maximum flow from S to T in the original graph:

    The maximum flow is 20 units, and here's how it's achieved:
    Path 1: S → A → C → T (flow: 10 units)
    Path 2: S → B → T (flow: 5 units)
    Path 3: S → A → B → T (flow: 5 units)
    Total: 10 + 5 + 5 = 20 units


    2. Flow after increasing A→C capacity from 10 to 15:

    The maximum flow remains 20 units even after the increase
    This is because:
    The bottleneck isn't at the A→C edge
    The limiting factor is the total capacity of edges reaching T:
    B→T has capacity 10
    C→T has capacity 10
    Therefore, maximum possible flow into T is 20 units
    Increasing A→C capacity doesn't help because we can't push more flow through the final edges to T
    The same paths are used to achieve the 20 units of flow*/

    return 0;
}

// main function to run question functions
int main()
{
    //taking input to which question to run
    printf("Enter the Question you want to run: ");
    int question;
    scanf("%d", &question);
    //if-else statement
    if (question == 1)
    {
        Question1();
    }
    else if (question == 2)
    {
        Question2();
    }
    else
    {
        printf("Question doesn't exist!!!");
    }
    
    return 0;
}