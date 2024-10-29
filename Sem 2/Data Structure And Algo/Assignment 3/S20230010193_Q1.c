#include <stdio.h>

//it will give 0 if not sorted
//it will give 1 if sorted
int issorted(int arr[], int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (arr[n - 1] >= arr[n - 2])
    {
        return issorted(arr, n - 1);
    }
    else
    {
        return 0;
    }
}

void main()
{
    int arr[11] = {1,2,3,4,5,6,78,89,765,1654,913456};
    printf("%d",issorted(arr,11));

    // recursive relation => T[n] = T[n-1] + 1;
    // time complexitty : O(n) where n is size of array
}