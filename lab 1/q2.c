/*1.2Write a program to store random numbers into an array of n integers, where the array must 
contains some duplicates. Do the following:

a)Find out the total number of duplicate elements.

b)Find out the most repeating element in the array.

Hints: Write the random generation function in such a way that it must generate some duplicate
 numbers. As for example if you generate 10 random numbers within a range say 11 to 15, then 
 atleast 5 numbers will be duplicate.

Input
Enter how many random numbers: 15
The content of the array with  random input are as follows:
10, 40, 35, 47, 68, 22, 40, 10, 98, 10, 50, 35, 68, 40, 10

Output
Total number of duplicates =  4
The most repeating element in the array = 10*/
#include <stdio.h>
#include <stdlib.h>

int find_duplicates(int array[], int n) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (array[i] == array[j]) {
        count++;
      }
    }
  }
  return count;
}

int find_most_repeating(int array[], int n) {
  int max_count = 0;
  int most_repeating = array[0];
  for (int i = 0; i < n; i++) {
    int count = 0;
    for (int j = i+1; j < n; j++) {
      if (array[i] == array[j]) {
        count++;
      }
    }
    if (count > max_count) {
      max_count = count;
      most_repeating = array[i];
    }
  }
  return most_repeating;
}

int main() {
  int n;
  printf("Enter how many random numbers: ");
  scanf("%d", &n);

  int array[n];
  for (int i = 0; i < n; i++) {
    array[i] = rand() % 15 + 1;
  }

  int total_duplicates = find_duplicates(array, n);
  int most_repeating = find_most_repeating(array, n);

  printf("Total number of duplicates = %d\n", total_duplicates);
  printf("The most repeating element in the array = %d\n", most_repeating);

  return 0;
}
