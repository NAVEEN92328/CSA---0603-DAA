#include <stdio.h>

struct Item {
    int weight, value;
};

void sortItems(struct Item arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((double)arr[j].value / arr[j].weight < (double)arr[j + 1].value / arr[j + 1].weight) {
                struct Item temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

double knapsack(struct Item arr[], int n, int W) {
    sortItems(arr, n);
    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + arr[i].weight <= W) {
            currentWeight += arr[i].weight;
            totalValue += arr[i].value;
        } else {
            totalValue += arr[i].value * ((double)(W - currentWeight) / arr[i].weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item arr[n];

    for (int i = 0; i < n; i++) {
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &arr[i].weight);
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &arr[i].value);
    }

    printf("Enter max weight of the knapsack: ");
    scanf("%d", &W);
    printf("Maximum value in the knapsack = %.2lf\n", knapsack(arr, n, W));

    return 0;
}

