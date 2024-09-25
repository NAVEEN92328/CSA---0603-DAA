#include <stdio.h>
#include <limits.h>

#define MAX 100

void optimalBST(int keys[], int freq[], int n) {
    int cost[MAX][MAX] = {0};
    
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            cost[i][j] = INT_MAX;
            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) + 
                        ((r < j) ? cost[r + 1][j] : 0) + freq[i] + freq[j];
                if (c < cost[i][j]) cost[i][j] = c;
            }
        }
    }

    printf("Cost of Optimal BST: %d\n", cost[0][n - 1]);
}

int main() {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);
    
    optimalBST(keys, freq, n);
    return 0;
}

