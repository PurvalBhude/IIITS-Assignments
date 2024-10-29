#include <stdio.h>
#include <stdlib.h>

// Question 1 (function)
void sparse_matrix_multiplication(int **arr1, int **arr2, int n1, int n2)
{
    int result[n1][3];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                for (int l = 1; l <= arr1[0][2]; l++)
                {
                    if (arr1[l][0] == i && arr1[l][1] == k)
                    {
                        for (int m = 1; m <= arr2[0][2]; m++)
                        {
                            if (arr2[m][0] == k && arr2[m][1] == j)
                            {
                                result[i][j] += arr1[l][2] * arr2[m][2];
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

// Question 3 (function)
void findAij(int q[], int n, int a, int b)
{
    int arr_size = (n / 3) + 1;
    int k = 0;
    int **p = (int **)malloc(sizeof(int *) * arr_size);
    for (int i = 0; i < arr_size; i++)
    {
        p[i] = (int *)malloc(sizeof(int) * arr_size);
    }

    for (int i = 0; i < arr_size; i++)
    {
        for (int j = 0; j < arr_size; j++)
        {
            if ((j == i) || (j == i - 1) || (j == i + 1))
            {
                p[i][j] = q[k];
                k++;
            }
            else
            {
                p[i][j] = 0;
            }
        }
    }

    printf("using your entered tri-diagonal regular sparse matrix array the created tridiagonal matrix : \n");
    for (int i = 0; i < arr_size; i++)
    {
        for (int j = 0; j < arr_size; j++)
        {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }

    if (a <= arr_size && b <= arr_size)
    {
        printf("Value at i,j is A(i,j) = %d", p[a][b]);
        return;
    }

    printf("At i,j the matrix is not defined");
    return;
}

int main()
{
    // Question 1
    // taking input for matrix 1
    // int n1;
    // printf("enter size of Sparse matrix_1 n1: ");
    // scanf("%d", &n1);
    // int **p = (int **)malloc(sizeof(int *) * n1);
    // for (int i = 0; i < n1; i++)
    // {
    //     p[i] = (int *)malloc(sizeof(int) * 3);
    // }
    // printf("Enter the elements in Sparse matrix_1:\n");
    // for (int i = 0; i < n1; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         scanf("%d", &p[i][j]);
    //     }
    // }
    // printf("\n");

    // // taking input for matrix 2
    // int n2;
    // printf("enter size of Sparse matrix_2 n2: ");
    // scanf("%d", &n2);
    // int **q = (int **)malloc(sizeof(int *) * n2);
    // for (int i = 0; i < n2; i++)
    // {
    //     q[i] = (int *)malloc(sizeof(int) * 3);
    // }
    // printf("Enter the elements in Sparse matrix_2:\n");
    // for (int i = 0; i < n1; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         scanf("%d", &q[i][j]);
    //     }
    // }
    // printf("\n");

    // printf("Created Sparse Matrix 1 is\n");
    // for (int i = 0; i < n1; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         printf("%d ", p[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("Created Sparse Matrix 2 is\n");
    // for (int i = 0; i < n2; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         printf("%d ", q[i][j]);
    //     }
    //     printf("\n");
    // }

    // sparse_matrix_multiplication(p, q, n1, n2);

    // Question 2
    //     int M,N,R;
    // printf("Enter Movies(M) , Cities(R) , people(N):");
    // scanf("%d %d %d",&M,&R,&N);

    // int ***p = (int ***) malloc(sizeof(int**)*M);
    // for(int i=0;i<M;i++){
    //     p[i] = (int **) malloc(sizeof(int *)*R);
    // }
    // for(int i=0;i<M;i++){
    //     for(int j=0;j<R;j++){
    //         p[i][j] = (int *) malloc(sizeof(int)*N);
    //     }
    // }
    // printf("enter the data of ratings of 1 to 5 (or zero if they have not seen it)\n");
    // for(int i=0;i<M;i++){
    //     for(int j=0;j<R;j++){
    //         printf("enter data for movie %d and city %d:\n",i+1,j+1);
    //         for(int k=0;k<N;k++){
    //             scanf("%d",&p[i][j][k]);
    //         }
    //     }
    // }

    // printf("Average Rating of Movie over all cities and people:\n");
    // int count,total_count,Average;

    // for(int i=0;i<M;i++){
    //     count = 0;
    //     total_count = 0;
    //     for(int j=0;j<R;j++){
    //         for(int k=0;k<N;k++){
    //             if(p[i][j][k] != 0){
    //                 count = count + p[i][j][k];
    //                 total_count++;
    //             }
    //         }
    //     }
    //     if(total_count != 0){
    //         Average = count/total_count;
    //         printf("Average Rating of movie %d is %d\n",i+1,Average);
    //     }
    // }

    // Question 3

    // int n;
    // printf("enter the size of array: ");
    // scanf("%d",&n);
    // int *q = (int*) malloc(sizeof(int)*n);
    // printf("Enter the values in array: \n");
    // for(int i=0;i<n;i++){
    //     scanf("%d",&q[i]);
    // }
    // int a,b;
    // printf("Enter the value of i and j for which you what value of A[i,j] :");
    // scanf("%d %d",&a,&b);
    // findAij(q,n,a,b);
}