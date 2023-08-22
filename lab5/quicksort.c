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

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int *A, int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);  // sort left subarray
        quickSort(A, partitionIndex + 1, high); // sort right subarray
    }
}

int main()
{

    //     int A[] = {12, 54, 65, 7, 23, 9};
    // int n = 6;
    // printArray(A, n);
    // insertionSort(A, n);
    // printArray(A, n);

    int n;
    printf("Enter how many random numbers: ");
    scanf("%d", &n);

    int A[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % 100 + 1; // create random int and store in randomAay
    }
    printArray(A, n);


    clock_t s, e;

    s = clock();
    // function call

    quickSort(A, 0, n - 1);
     printArray(A, n);

    e = clock();
    double t = (double)(e - s) / CLOCKS_PER_SEC;

    printf(" %f\n", t);

    return 0;
}
