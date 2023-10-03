#include <stdio.h>
#include <stdlib.h>

void activity_Selection(int s[], int f[], int n)
{
    int i, j = 1;
    printf(" Activity Selected ");
    printf("A[%d]", j);
    for (i = 2; i <= n; i++)
    {
        if (s[i] >= f[j])
        {
            printf("A[%d] ", i);
            j = i;
        }
    }
    printf(" ");
}

int main()
{
    int n;
    printf("Enter the no. of activity:");
    scanf("%d", &n);
    int  s[n], f[n];
    for (int i = 1; i <= n; i++)
    {
        printf("Enter the start time  for activity A[%d]:", i);
        scanf("%d", &s[i]);
        printf("Enter the finish time  for activity A[%d]:", i);
        scanf("%d", &f[i]);
    }

    activity_Selection(s, f, n);
    return 0;
}