#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int *A, int mid, int low, int high)
{
    int i, j, k;
    i = j = low;
    j = mid + 1;
    int B[100000];
    while (i < mid && j < high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i < mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j < high)
    {

        B[k] = A[j];
        j++;
        k++;
    }
}

void mergeSort(int *A, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

int main()
{

    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int A[n];
    // printf("enter array elements");
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d",&A[i]); // create random int and store in randomAay
    // }
    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % 100 + 1; // create random int and store in randomAay
    }


    printArray(A, n);

    mergeSort(A, 0, n - 1);
    printArray(A, n);

    return 0;
}
