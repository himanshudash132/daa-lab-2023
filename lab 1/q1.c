#include <stdio.h>
#include <stdlib.h>

/*Write a program to store random numbers into an array of n integers and then find out the smallest and largest number stored in it.
Input
Enter how many random numbers 👎: 10
The content of the array with  random input are as follows:
10, 40, 35, 47, 68, 22, 40, 46, 98, 10
Output
The smallest number is 10
The largest number is 98*/

void  find_smallest_and_largest(int arr[], int n, int *smallest, int *largest)
{
    *smallest = *largest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < *smallest)
            *smallest = arr[i];
        if (arr[i] > *largest)
            *largest = arr[i];
            
    }

}

int main()
{
    int n;
    printf("Enter how many random numbers: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100 + 1; // create random int and store in randomArray
    }
    int smallest, largest;
    find_smallest_and_largest(arr, n, &smallest, &largest);

    printf("The smallest number is %d\n", smallest);
    printf("The largest number is %d\n", largest);

    return 0;
}