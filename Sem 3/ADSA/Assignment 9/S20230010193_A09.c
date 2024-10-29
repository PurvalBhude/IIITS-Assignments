/*
* Name : Purval Madhukar Bhude
* Roll No. S20230010193
* Assignment 9 ADSA
*/

#include <stdio.h>
#include <stdlib.h>

int ans_index = 0;

int empty(int front, int rear)
{
    return front > rear;
}

int *bfs(int nodes, int **adj, int starting, int *distances)
{
    int *visit = (int *)calloc(nodes + 1, sizeof(int));
    int *queue = (int *)malloc((nodes + nodes) * sizeof(int));
    int *ans = (int *)malloc((nodes + 1) * sizeof(int));
    int front = 0, rear = 0, index = 0;
    queue[rear++] = starting;
    visit[starting] = 1;
    distances[starting] = 0;

    while (!empty(front, rear - 1))
    {
        int temp = queue[front++];
        ans[index++] = temp;

        for (int i = 0; adj[temp][i] != -1; i++)
        {
            int neighbor = adj[temp][i];
            if (!visit[neighbor])
            {
                queue[rear++] = neighbor;
                visit[neighbor] = 1;
                distances[neighbor] = distances[temp] + 1;
            }
        }
    }
    free(queue);
    free(visit);
    return ans;
}

void rec(int node, int **adj, int *ans, int *visit, int parent)
{
    ans[ans_index++] = node;
    visit[node] = 1;

    for (int i = 0; adj[node][i] != -1; i++)
    {
        int neighbor = adj[node][i];
        if (!visit[neighbor])
        {
            rec(neighbor, adj, ans, visit, node);
        }
    }
}

int *dfs(int **adj, int nodes, int starting)
{
    int *visited = (int *)calloc(nodes + 1, sizeof(int));
    int *ans = (int *)malloc(nodes * sizeof(int));
    ans_index = 0;
    rec(starting, adj, ans, visited, -1);
    free(visited);
    return ans;
}

int main()
{
    printf("enter the question which has to be run: ");
    int option;
    scanf("%d", &option);
    if (option == 1)
    {
        int nodes, edges;
        printf("Enter number of nodes: ");
        scanf("%d", &nodes);
        printf("Enter number of edges: ");
        scanf("%d", &edges);

        int **adj = (int **)malloc((nodes + 1) * sizeof(int *));
        for (int i = 0; i <= nodes; i++)
        {
            adj[i] = (int *)malloc((nodes + 1) * sizeof(int));
            for (int j = 0; j <= nodes; j++)
            {
                adj[i][j] = -1;
            }
        }
        printf("Enter edges in (n m) format: ");
        for (int i = 0; i < edges; i++)
        {
            int n, m;
            scanf("%d %d", &n, &m);

            int j = 0;
            while (adj[n][j] != -1)
                j++;
            adj[n][j] = m;

            j = 0;
            while (adj[m][j] != -1)
                j++;
            adj[m][j] = n;
        }

        printf("Enter the starting node: ");
        int starting_node;
        scanf("%d", &starting_node);

        int *ans = dfs(adj, nodes, starting_node);

        printf("DFS Traversal: ");
        for (int i = 0; i < ans_index; i++)
        {
            printf("%d ", ans[i]);
        }
        printf("\n");

        if (ans_index != nodes)
        {
            printf("Cycle Detection: Cycle Exists\n");
        }
        else
        {
            printf("Cycle Detection: No Cycle\n");
        }

        for (int i = 0; i <= nodes; i++)
        {
            free(adj[i]);
        }
        free(adj);
        free(ans);
    }
    else if (option == 2)
    {
        int nodes, edges;
        printf("Enter number of nodes: ");
        scanf("%d", &nodes);
        printf("Enter number of edges: ");
        scanf("%d", &edges);

        int **adj = (int **)malloc((nodes + 1) * sizeof(int *));
        for (int i = 0; i <= nodes; i++)
        {
            adj[i] = (int *)malloc((nodes + 1) * sizeof(int));
            for (int j = 0; j <= nodes; j++)
            {
                adj[i][j] = -1;
            }
        }

        printf("Enter edges in (n m) format: ");
        for (int i = 0; i < edges; i++)
        {
            int n, m;
            scanf("%d %d", &n, &m);

            int j = 0;
            while (adj[n][j] != -1)
                j++;
            adj[n][j] = m;

            j = 0;
            while (adj[m][j] != -1)
                j++;
            adj[m][j] = n;
        }

        printf("Enter the starting node: ");
        int starting_node;
        scanf("%d", &starting_node);

        int *distances = (int *)malloc((nodes + 1) * sizeof(int));
        for (int i = 0; i <= nodes; i++)
        {
            distances[i] = -1;
        }

        int *ans = bfs(nodes, adj, starting_node, distances);

        printf("BFS Traversal: ");
        for (int i = 0; i < nodes && ans[i] != 0; i++)
        {
            printf("%d ", ans[i]);
        }
        printf("\n");

        for (int i = 0; i <= nodes; i++)
        {
            free(adj[i]);
        }
        free(adj);
        free(ans);
        free(distances);
    }
    else
    {
        printf("no such question found!!!");
    }
    return 0;
}
