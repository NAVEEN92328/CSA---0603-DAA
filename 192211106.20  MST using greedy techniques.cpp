#include <stdio.h>
#include <limits.h>

#define V 5  

int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    return min_index;
}

void primMST(int graph[V][V]) {
    int parent[V], key[V];
    int mstSet[V] = {0};

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
    }

    key[0] = 0;  

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 9, 4, 0},
        {2, 0, 3, 3, 0, 7},
        {0, 3, 0, 5, 0, 8},
        {1, 3, 5, 0, 9, 0},
        {4, 0, 0, 9, 0, 0},
        {0, 7, 8, 0, 0, 0}
    };

    primMST(graph);
    return 0;
}

