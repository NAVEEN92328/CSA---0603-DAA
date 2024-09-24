#include <stdio.h>
#include <limits.h>

#define MAX 10

int n;
int distance[MAX][MAX]; 
int visited[MAX];
int min_cost = INT_MAX; 

void tsp(int current_city, int count, int cost) {
    if (count == n && distance[current_city][0]) {
      
        int total_cost = cost + distance[current_city][0];
        if (total_cost < min_cost) {
            min_cost = total_cost;
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && distance[current_city][i]) {
            visited[i] = 1; 
            tsp(i, count + 1, cost + distance[current_city][i]);
            visited[i] = 0; 
        }
    }
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &distance[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    visited[0] = 1; 
    tsp(0, 1, 0);

    printf("Minimum cost of traveling: %d\n", min_cost);
    return 0;
}

