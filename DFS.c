#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

void dfs(int v, int numVertices) {
    visited[v] = 1;
    printf("%d\t", v);

    for (int i = 0; i < numVertices; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            dfs(i, numVertices);
        }
    }
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    // Initialize visited array
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    // Input the edges
    printf("Enter the start and end vertices of the edges:\n");
    for (int i = 0; i < numEdges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        graph[start][end] = 1;
    }

    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    printf("DFS traversal starting from vertex %d:\n", startVertex);
    dfs(startVertex, numVertices);

    return 0;
}
