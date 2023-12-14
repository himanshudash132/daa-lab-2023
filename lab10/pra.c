#include <stdio.h>
int MatrixChainMultuplication(int arr[], int n) {
    int m[n][n];
    int j,q;
    for (int i = 1; i < n; i++)
    m[i][i] = 0;
    for(int L = 2;L < n; L++){
        for(int i = 1; i < n - L + 1; i++){
            int j = i + L - 1;
            m[i][j] = 99999999;
            for(int k = i; k <= j - 1; k++){
                q = m[i][k] + m[k+1][j] + arr[i - 1]*arr[k]*arr[j];
                if (q < m[i][j])
                m[i][j] = q;
            }
        }
    }
    return m[1][n-1];
}
int main(){
    int arr[] = {3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Minimum number of multiplications required for the matrices multiplication is %d ", MatrixChainMultuplication(arr, size));

    return 0;
}