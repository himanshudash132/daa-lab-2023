#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int* A, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertionSort(int *A, int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int key = A[i];
        int j = i - 1;
        while (A[j] > key && j >= 0)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int binarySearch(int *A, int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    // Keep searching until low <= high
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (A[mid] == element)
        {
            return mid;
        }
        if (A[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
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
    // printArray(A, n);

    int size = sizeof(A) / sizeof(int);
    int element;

    printf("Enter the element to be searched:\n");
    scanf("%d", &element);

   

    clock_t s, e;

    s = clock();
    // function call
     insertionSort(A, n);
    int searchIndex = binarySearch(A, size, element);
    printf("The element %d was found at index %d \n", element, searchIndex);
    e = clock();
    double t = (double)(e - s) / CLOCKS_PER_SEC;

    printf(" %f\n", t);

    return 0;
}