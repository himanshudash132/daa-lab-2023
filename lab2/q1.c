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

void selectionSort(int *A, int n)
{
    int indexOfMin, temp;
    printf("Running Selection sort...\n");
    for (int i = 0; i < n - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        // Swap A[i] and A[indexOfMin]
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}

void Reversed(int *A, int start, int end)
{
    int temp;
    printf("Rerersing_the_array\n");
    while (start < end)
    {
        temp = A[start];
        A[start] = A[end];
        A[end] = temp;
        start++;
        end--;
    }
}

void random_array(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % 1000 + 1; // create random int and store in randomArray
    }
}

int main()
{

    int n;
    printf("Enter how many random numbers: ");
    scanf("%d", &n);

    int arr[n];

    int ch;
    clock_t start, end;
    double t = (double)(end - start) / CLOCKS_PER_SEC;
    printf("1->random input\n 2->sorted input time\n 3->reverse input time\n");
    scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            start = clock();
            // function call
            random_array(arr, n);
            end = clock();
            printf(" %f\n", t);
            break;

        case 2:
            start = clock();
            // function call
            random_array(arr, n);
            selectionSort(arr, n);
            end = clock();
            printf(" %f\n", t);
            break;
        case 3:
            start = clock();
            // function call
            random_array(arr, n);
            Reversed(arr, 0, n - 1);
            end = clock();
            printf(" %f\n", t);
            break;

        case 4:
            exit(0);
        }
   

    return 0;
}
