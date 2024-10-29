#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

// Question 1
int nextdate(int n)
{
    int day = n / 1000000;
    int month = (n / 10000) % 100;
    int year = n % 10000;

    int month31[] = {1, 3, 5, 7, 8, 10, 12};
    int month30[] = {4, 6, 9, 11};

    int month28 = 2;

    if (day <= 27)
    {
        day++;
    }
    else
    {
        // for months which has 31 days in month
        for (int i = 0; i < 7; i++)
        {
            if (month == month31[i])
            {
                if (day <= 30)
                {
                    day++;
                    break;
                }
                else
                {
                    day = 1;
                    if (month == 12)
                    {
                        month = 1;
                        year++;
                    }
                    else
                    {
                        month++;
                    }
                }
            }
        }

        // for month which has 30 days in month
        for (int i = 0; i < 4; i++)
        {
            if (month == month30[i])
            {
                if (day <= 29)
                {
                    day++;
                    break;
                }
                else
                {
                    day = 1;
                    if (month == 12)
                    {
                        month = 1;
                        year++;
                    }
                    else
                    {
                        month++;
                    }
                }
            }
        }

        // for feb month as it has 28days in non leap year and 29days in leap year
        if (month == month28)
        {
            if (year % 4 == 0)
            {
                if (day <= 28)
                {
                    day++;
                }
                else
                {
                    day = 1;
                    month++;
                }
            }
            else
            {
                day = 1;
                month++;
            }
        }
    }

    n = (day * 1000000) + (month * 10000) + (year);
    printf("Day: %d, month: %d, year: %d\n", day, month, year);
    return n;
}

// Question 2 (a)
int search(int arr[], int n, int key)
{
    clock_t start, end;
    start = clock();

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("1\n");
            end = clock();
            double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("time taken %f", time_taken);
            return 1;
        }
    }
    printf("0\n");

    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("time taken %f", time_taken);
    return 0;
}

// Question 2 (b)
int multipletimes(int arr[], int n)
{
    clock_t start, end;
    start = clock();

    int result = -1;
    int count = 0;
    int max = -1;
    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > max)
        {
            max = count;
            result = arr[i];
        }
    }
    printf("%d\n", result);
    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("time taken %f", time_taken);
    return result;
}

int main()
{
    // test case for Q1
    //  int date = 29022024;
    //  printf("%d",nextdate(date));

    // test case for Q2 (a)
    //  int arr[] = {1,3,5,7,9,11,13,15,17,19};
    //  int n = 10;
    //  int key = 13;
    //  search(arr,n,key);

    // test case for Q2 (b)
    // int arr[] = {2,5,3,1, 2, 2, 3};
    // int n = 7;
    // multipletimes(arr, n);

    // For Q3 graph is in output file
    // int n = 100000;
    // int key = 1003;
    // int * arr = (int *) malloc(sizeof(int)*n);
    // for(int i=10;i<100000;i++){
    //     arr[i] = rand();
    // }
    // search(arr, n,key);
}