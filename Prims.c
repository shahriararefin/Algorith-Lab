#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100
#define INFINITY 9999

int graph[MAX_VERTICES][MAX_VERTICES];
int selected[MAX_VERTICES];
int numVertices;

void prim() {
    int totalCost = 0;

    // Initialize selected array
    for (int i = 0; i < numVertices; i++) {
        selected[i] = false;
    }

    // Select first vertex as starting vertex
    selected[0] = true;

    // Print MST edges
    printf("Minimum Spanning Tree Edges:\n");

    // MST has numVertices-1 edges
    for (int edgeCount = 0; edgeCount < numVertices - 1; edgeCount++) {
        int minWeight = INFINITY;
        int startVertex, endVertex;

        for (int i = 0; i < numVertices; i++) {
            if (selected[i]) {
                for (int j = 0; j < numVertices; j++) {
                    if (!selected[j] && graph[i][j]) {
                        if (graph[i][j] < minWeight) {
                            minWeight = graph[i][j];
                            startVertex = i;
                            endVertex = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d\tWeight: %d\n", startVertex, endVertex, minWeight);
        totalCost += minWeight;
        selected[endVertex] = true;
    }

    printf("Total Cost of MST: %d\n", totalCost);
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    prim();

    return 0;
}
