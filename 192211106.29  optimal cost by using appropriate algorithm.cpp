#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int weight[], int value[], int n, int W) {
    int K[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weight[i - 1] <= w)
                K[i][w] = max(K[i - 1][w], K[i - 1][w - weight[i - 1]] + value[i - 1]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    int weight[n], value[n];

    printf("Enter weights:\n");
    for (int i = 0; i < n; i++) scanf("%d", &weight[i]);
    printf("Enter values:\n");
    for (int i = 0; i < n; i++) scanf("%d", &value[i]);
    printf("Enter maximum weight: ");
    scanf("%d", &W);

    printf("Optimal cost: %d\n", knapsack(weight, value, n, W));
    return 0;
}

