#include <stdio.h>

int parent[10];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int union1(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int mincost = 0, cost[10][10], n, i, j, ne = 1;
    int a, b, u, v, min;

    printf("Enter the number of vertices of the graph: \n");
    scanf("%d", &n);
    
    printf("Enter the cost matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) 
                cost[i][j] = 999;
        }
    }

    printf("\nThe edges of the minimum spanning tree are:\n");

    while (ne < n) {
        for (min = 999, i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (union1(u, v)) {
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }
        
        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nThe minimum cost of the spanning tree is %d\n", mincost);

    return 0;
}
