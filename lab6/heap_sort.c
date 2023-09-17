// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// void swap(int *X, int *Y)
// {
//     int temp;
//     temp = *X;
//     *X = *Y;
//     *Y = temp;
// }

// void printArray(int *A, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", A[i]);
//     }
//     printf("\n");
// }


// void Maxheapify(int *A, int n, int i)
// {
//     int largest = i;
//     int l = (2 * i) + 1;
//     int r = (2 * i) + 2;

//     if (l <= n && A[l] > A[largest])
//     {
//         largest = l;
//     }
//     if (r <= n && A[r] > A[largest])
//     {
//         largest = r;
//     }
//     if (largest != i)
//     {
//         swap(&A[largest], &A[i]);

//         Maxheapify(A, n, largest);
//     }
// }

// void heapSort(int *A, int n)
// {
//     for (int i = n / 2; i >= 1; i--)
//     {
//         Maxheapify(A, n, i);
//     }
//     for (int i = n; i >= 1; i--)
//     {
//         swap(&A[1], &A[i]);

//         Maxheapify(A, i - 1, 1);
//     }
// }

// int main()
// {



//     int n;
//     printf("Enter how many random numbers: ");
//     scanf("%d", &n);

//     int A[n];
//     for (int i = 0; i < n; i++)
//     {
//         A[i] = rand() % 100 + 1; // create random int and store in randomAay
//     }

//     // clock_t s, e;

//     // s = clock();
//     // // function call

//     // heapSort(A, n);
//     // printArray(A, n);

//     // e = clock();
//     // double t = (double)(e - s) / CLOCKS_PER_SEC;

//     // printf(" %f\n", t);

//     printArray(A, n);
//     heapSort(A, n);
//     printArray(A, n);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void reverssearr(int arr[], int n) {
    int start = 0, end = n - 1;
    while (start < end) {
        swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
}

int main() {
    clock_t s, e;
    int n, i;
    int max, min;
    printf("Enter upper and lower limit: ");
    scanf("%d %d", &min, &max);
    printf("Enter size of an array: ");
    scanf("%d", &n);
    
   
    s = clock();
    int arr[n];
    for (i = 0; i < n; i++) {
        arr[i] = (rand() % (max - min + 1)) + min;
    }
    e = clock();

    double t_generate = ((double)(e - s)) / CLOCKS_PER_SEC;
    printf("\nTime taken to generate elements: %f\n", t_generate);

   
    s = clock();
    heapSort(arr, n);
    e = clock();

    double t_heap_sort = ((double)(e - s)) / CLOCKS_PER_SEC;
    printf("Time taken by Heap Sort: %f\n", t_heap_sort);

    
    clock_t s1, e1, s2, e2, e3, s3;

    s1 = clock();
    heapSort(arr, n);
    e1 = clock();
    double t1 = ((double)(e1 - s1)) / CLOCKS_PER_SEC;
 

    reverssearr(arr, n);

    s3 = clock();
    heapSort(arr, n);
e3 = clock();
    double t3 = ((double)(e3 - s3)) / CLOCKS_PER_SEC;
    printf("Time taken by sorting a reversed array: %f\n", t3);

    return 0;
}