#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100
#define MAX_EDGES 100

// Structure to represent an edge
struct Edge {
    int startVertex;
    int endVertex;
    int weight;
};

struct Edge edgeList[MAX_EDGES];
int parent[MAX_VERTICES];
int numVertices, numEdges;

// Function to compare two edges based on weight
int compare(const void *a, const void *b) {
    struct Edge *edgeA = (struct Edge *)a;
    struct Edge *edgeB = (struct Edge *)b;
    return edgeA->weight - edgeB->weight;
}

// Find parent of a vertex in disjoint set
int find(int vertex) {
    if (parent[vertex] == -1)
        return vertex;
    return find(parent[vertex]);
}

// Perform union of two subsets in disjoint set
void unionSet(int x, int y) {
    parent[x] = y;
}

void kruskal() {
    struct Edge result[MAX_EDGES];
    int resultIndex = 0;
    int totalCost = 0;

    // Sort edges in non-decreasing order of weight
    qsort(edgeList, numEdges, sizeof(struct Edge), compare);

    // Initialize parent array
    for (int i = 0; i < numVertices; i++) {
        parent[i] = -1;
    }

    // Process each edge in sorted order
    for (int i = 0; i < numEdges; i++) {
        int startVertex = edgeList[i].startVertex;
        int endVertex = edgeList[i].endVertex;
        int startParent = find(startVertex);
        int endParent = find(endVertex);

        // Add the edge to the result if it doesn't form a cycle
        if (startParent != endParent) {
            result[resultIndex++] = edgeList[i];
            totalCost += edgeList[i].weight;
            unionSet(startParent, endParent);
        }
    }

    // Print MST edges
    printf("Minimum Spanning Tree Edges:\n");
    for (int i = 0; i < resultIndex; i++) {
        printf("%d - %d\tWeight: %d\n", result[i].startVertex, result[i].endVertex, result[i].weight);
    }

    printf("Total Cost of MST: %d\n", totalCost);
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the start vertex, end vertex, and weight of each edge:\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &edgeList[i].startVertex, &edgeList[i].endVertex, &edgeList[i].weight);
    }

    kruskal();

    return 0;
}
