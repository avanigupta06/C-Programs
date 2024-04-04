#include <stdio.h>
#include <stdlib.h>

// Maximum number of cities
#define MAX_CITIES 10

// Function prototypes
void createGraph(int graph[MAX_CITIES][MAX_CITIES], int n);
void printGraph(int graph[MAX_CITIES][MAX_CITIES], int n);
void DFS(int graph[MAX_CITIES][MAX_CITIES], int visited[MAX_CITIES], int start, int n);
void BFS(int graph[MAX_CITIES][MAX_CITIES], int visited[MAX_CITIES], int start, int n);

int main() {
    int graph[MAX_CITIES][MAX_CITIES], n, start;

    // Input the number of cities
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    // Create the graph
    createGraph(graph, n);

    // Print the graph
    printf("\nGraph (Adjacency Matrix):\n");
    printGraph(graph, n);

    // Input the starting city for DFS and BFS
    printf("\nEnter the starting city for DFS and BFS: ");
    scanf("%d", &start);

    // Perform DFS
    printf("\nDFS Traversal:\n");
    int visitedDFS[MAX_CITIES] = {0};
    DFS(graph, visitedDFS, start, n);

    // Perform BFS
    printf("\nBFS Traversal:\n");
    int visitedBFS[MAX_CITIES] = {0};
    BFS(graph, visitedBFS, start, n);

    return 0;
}

// Function to create the graph using an Adjacency Matrix
void createGraph(int graph[MAX_CITIES][MAX_CITIES], int n) {
    int i, j;

    // Initialize the graph with zeros
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input the edges
    printf("Enter the adjacency matrix (1 if there is an edge, 0 otherwise):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

// Function to print the graph (Adjacency Matrix)
void printGraph(int graph[MAX_CITIES][MAX_CITIES], int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// Depth First Search (DFS) function
void DFS(int graph[MAX_CITIES][MAX_CITIES], int visited[MAX_CITIES], int start, int n) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            DFS(graph, visited, i, n);
        }
    }
}

// Breadth First Search (BFS) function
void BFS(int graph[MAX_CITIES][MAX_CITIES], int visited[MAX_CITIES], int start, int n) {
    int queue[MAX_CITIES];
    int front = -1, rear = -1;

    printf("%d ", start);
    visited[start] = 1;
    queue[++rear] = start;

    while (front != rear) {
        int current = queue[++front];

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}
