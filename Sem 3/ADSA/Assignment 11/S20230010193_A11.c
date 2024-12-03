/*
* Name : Purval Madhukar Bhude
* Roll No. S20230010193
* ADSA Assignment 11
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INFINITY 99999

// Custom structure with unique names
struct SubseqResult {
    int matchCount;
    char* commonChars;
};

// Utility function with unique name
int biggerNum(int firstNum, int secondNum) {
    return (firstNum > secondNum) ? firstNum : secondNum;
}

struct SubseqResult findMatchingChars(char* firstStr, char* secondStr) {
    int firstLen = strlen(firstStr);
    int secondLen = strlen(secondStr);
    int** matchTable = (int**)malloc((firstLen + 1) * sizeof(int*));
    for (int row = 0; row <= firstLen; row++) {
        matchTable[row] = (int*)malloc((secondLen + 1) * sizeof(int));
    }
    
    for(int row = 0; row <= firstLen; row++) {
        matchTable[row][0] = 0;
    }
    for(int col = 0; col <= secondLen; col++) {
        matchTable[0][col] = 0;
    }
    
    for(int row = 1; row <= firstLen; row++) {
        for(int col = 1; col <= secondLen; col++) {
            if (firstStr[row-1] == secondStr[col-1]) {
                matchTable[row][col] = matchTable[row-1][col-1] + 1;
            } else {
                matchTable[row][col] = biggerNum(matchTable[row-1][col], 
                                               matchTable[row][col-1]);
            }
        }
    }
    
    int totalMatches = matchTable[firstLen][secondLen];
    
    char* resultSequence = (char*)malloc((totalMatches + 1) * sizeof(char));
    resultSequence[totalMatches] = '\0';
    
    int currentPos = totalMatches - 1;
    int row = firstLen;
    int col = secondLen;
    
    for(int i = 0; i < totalMatches; i++) {
        for(; row > 0 && col > 0;) {
            if(firstStr[row-1] == secondStr[col-1]) {
                resultSequence[currentPos] = firstStr[row-1];
                row--;
                col--;
                currentPos--;
                break;
            }
            else if(matchTable[row-1][col] > matchTable[row][col-1]) {
                row--;
            }
            else {
                col--;
            }
        }
    }
    
    for(int row = 0; row <= firstLen; row++) {
        free(matchTable[row]);
    }
    free(matchTable);
    
    struct SubseqResult finalResult;
    finalResult.matchCount = totalMatches;
    finalResult.commonChars = resultSequence;
    
    return finalResult;
}

int main1() {
    char firstString[] = "AGGTAB";
    char secondString[] = "GXTXAYB";
    
    printf("First String: %s\n", firstString);
    printf("Second String: %s\n", secondString);
    
    struct SubseqResult output = findMatchingChars(firstString, secondString);
    
    printf("\nNumber of matching characters: %d\n", output.matchCount);
    printf("Matching sequence: %s\n", output.commonChars);
    
    free(output.commonChars);
    
    return 0;
}

// Structure to represent a graph
typedef struct GraphStructure {
    int numVertices;
    int distanceMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to initialize the graph
void initializeGraph(Graph* graph, int vertices) {
    graph->numVertices = vertices;
    
    int source = 0;
    do {
        int destination = 0;
        do {
            if (source == destination) {
                graph->distanceMatrix[source][destination] = 0;
            } else {
                graph->distanceMatrix[source][destination] = INFINITY;
            }
            destination++;
        } while (destination < vertices);
        source++;
    } while (source < vertices);
}

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

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Function to add an edge to the graph
void addGraphEdge(Graph* graph, int source, int destination, int weight) {
    if (source >= 0 && source < graph->numVertices && 
        destination >= 0 && destination < graph->numVertices) {
        graph->distanceMatrix[source][destination] = weight;
    }
}

// Function to display the distance matrix
void displayDistanceMatrix(Graph* graph, const char* message) {
    printf("\n%s\n", message);
    
    int rowIndex = 0;
    while (rowIndex < graph->numVertices) {
        int columnIndex = 0;
        printf("[ ");
        while (columnIndex < graph->numVertices) {
            if (graph->distanceMatrix[rowIndex][columnIndex] == INFINITY) {
                printf("INF ");
            } else {
                printf("%3d ", graph->distanceMatrix[rowIndex][columnIndex]);
            }
            columnIndex++;
        }
        printf("]\n");
        rowIndex++;
    }
}

// Function to find shortest paths using Floyd-Warshall algorithm
void findShortestPaths(Graph* graph, bool showSteps) {
    int vertices = graph->numVertices;
    
    int tempMatrix[MAX_VERTICES][MAX_VERTICES];
    
    int row = 0;
    do {
        int col = 0;
        do {
            tempMatrix[row][col] = graph->distanceMatrix[row][col];
            col++;
        } while (col < vertices);
        row++;
    } while (row < vertices);
    
    int intermediate = 0;
    do {
        int source = 0;
        do {
            int destination = 0;
            do {
                int currentPath = tempMatrix[source][destination];
                int newPath = tempMatrix[source][intermediate] + 
                             tempMatrix[intermediate][destination];
                
                if (tempMatrix[source][intermediate] != INFINITY && 
                    tempMatrix[intermediate][destination] != INFINITY && 
                    newPath < currentPath) {
                    tempMatrix[source][destination] = newPath;
                }
                destination++;
            } while (destination < vertices);
            source++;
        } while (source < vertices);
        
        if (showSteps) {
            printf("\nAfter considering vertex %d as intermediate:", intermediate);
            int i = 0;
            while (i < vertices) {
                printf("\n[ ");
                int j = 0;
                while (j < vertices) {
                    if (tempMatrix[i][j] == INFINITY) {
                        printf("INF ");
                    } else {
                        printf("%3d ", tempMatrix[i][j]);
                    }
                    j++;
                }
                printf("]");
                i++;
            }
            printf("\n");
        }
        
        intermediate++;
    } while (intermediate < vertices);
    
    row = 0;
    do {
        int col = 0;
        do {
            graph->distanceMatrix[row][col] = tempMatrix[row][col];
            col++;
        } while (col < vertices);
        row++;
    } while (row < vertices);
}

int main2() {
    Graph graph;
    int numVertices = 4;
    initializeGraph(&graph, numVertices);
    
    addGraphEdge(&graph, 0, 1, 3);
    addGraphEdge(&graph, 0, 3, 7);
    addGraphEdge(&graph, 1, 2, 2);
    addGraphEdge(&graph, 2, 3, 1);
    addGraphEdge(&graph, 1, 0, 8);
    addGraphEdge(&graph, 2, 0, 5);
    addGraphEdge(&graph, 3, 0, 2);
    
    displayDistanceMatrix(&graph, "Initial Distance Matrix:");
    
    findShortestPaths(&graph, true);
    
    displayDistanceMatrix(&graph, "\nFinal Shortest Distances Matrix:");
    
    return 0;
}

int main(){
    printf("enter the question you want to run: ");
    int question;
    scanf("%d",&question);

    if(question==1){
        main1();
    }
    else if(question==2){
        main2();
    }
    else{
        printf("No such question found !!! ");
    }
}