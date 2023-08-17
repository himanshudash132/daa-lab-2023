/*Write a program to display an array of n integers (n>1), where at every index of the
 array should contain the product of all elements in the array except the element at 
 the given index. Solve this problem by taking single loop and without an additional array.

Input Array  : 3  4  5  1  2
Output Array :40  30  24  120  60*/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void main()
{
    time_t _time;
    srand((unsigned)time(&_time));
    int number;
    printf("Enter number of numbers in an array ");
    scanf("%d", &number);

    int array[number];
    int i, product = 1;
    printf("Numbers are :");
    for (i = 0; i < number; i++)
    {
        array[i] = 1 + (int)rand() % (number);
        printf(" %d", array[i]);
        product *= array[i];
    }
    printf("\nNew array is :");
    for(i = 0; i<number; i++)
    {
        array[i] = product/array[i];
        printf(" %d", array[i]);
    }
}