#include <stdio.h>
#include <limits.h>

#define MAX 20
#define INF INT_MAX

int n, dist[MAX][MAX], dp[1 << MAX][MAX];

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) return dist[pos][0]; 
    if (dp[mask][pos] != -1) return dp[mask][pos];

    int ans = INF;
    for (int city = 0; city < n; city++) {
        if (!(mask & (1 << city))) { 
            ans = ans < dist[pos][city] + tsp(mask | (1 << city), city) ? ans : dist[pos][city] + tsp(mask | (1 << city), city);
        }
    }
    return dp[mask][pos] = ans;
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);
    printf("Enter distance matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &dist[i][j]);

    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = -1; 

    printf("Minimum cost: %d\n", tsp(1, 0)); 
    return 0;
}

