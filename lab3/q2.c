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

void bubbleSort(int *A, int n){
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n-1; i++) // For number of pass
    {
       
        for (int j = 0; j <n-1-i ; j++) // For comparison in each pass
        {
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp; 
            }
        }  
    } 
}






int main()
{



    // int A[] = {3, 5, 2, 13, 12};
    // int n = 5;
    // printArray(A, n);
    // selectionSort(A, n);
    // printArray(A, n);

    int n;
    printf("Enter how many random numbers: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100 + 1; // create random int and store in randomArray
    }
    // printArray(arr, n);

    // selectionSort(arr, n);

    clock_t s, e;

    s = clock();
    // function call 
     bubbleSort(arr, n);


    e = clock();
    double t = (double)(e -s) / CLOCKS_PER_SEC;

    printf(" %f\n", t);


    return 0;
}