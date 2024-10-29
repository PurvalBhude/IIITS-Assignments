#include <stdio.h>
#include <time.h>

double copy1(int arr[6000][6000], int cpy[6000][6000])
{
    clock_t start = clock();
    for (int i = 0; i < 6000; i++)
    {
        for (int j = 0; j < 6000; j++)
        {
            cpy[i][j] = arr[i][j];
        }
    }
    clock_t end = clock();
    double ans = (double)(end - start)/ CLOCKS_PER_SEC;
    return ans;
}

double copy2(int arr[6000][6000], int cpy[6000][6000])
{
    clock_t start = clock();
    for (int j = 0; j < 6000; j++)
    {
        for (int i = 0; i < 6000; i++)
        {
            cpy[i][j] = arr[i][j];
        }
    }
    clock_t end = clock();
    double ans = (double)(end - start)/ CLOCKS_PER_SEC;
    return ans;
}

int main()
{
    printf("Program start\n");
    // int arr[6000][6000];
    // int cpy[6000][6000];

    int (*arr)[6000] = malloc(6000*sizeof(*arr));
    int (*cpy)[6000] = malloc(6000*sizeof(*cpy));

    for (int i = 0; i < 6000; i++)
    {
        for (int j = 0; j < 6000; j++)
        {
            arr[i][j] = i;
        }
    }

    printf("Time complexity of copy1: %f\n", copy1(arr, cpy));
    printf("Time complexity of copy2: %f\n", copy2(arr, cpy));
    printf("Program end\n");
}
