#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Graph represented as an adjacency list
int adj[MAX][MAX];
int visited[MAX];
int front = 0, rear = -1;
int queue[MAX];

void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1; // Since the graph is undirected
}

// BFS traversal using a queue
void bfs(int start, int n) {
    for (int i = 0; i < n; i++) visited[i] = 0;

    front = 0;
    rear = -1;

    queue[++rear] = start;
    visited[start] = 1;

    printf("BFS Traversal: %d ", start);

    while (front <= rear) {
        int current = queue[front++];
        for (int i = 0; i < n; i++) {
            if (adj[current][i] && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
                printf("%d ", i);
            }
        }
    }
    printf("\n");
}

// DFS traversal using recursion
void dfsUtil(int v, int n) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfsUtil(i, n);
        }
    }
}

void dfs(int start, int n) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    printf("DFS Traversal: ");
    dfsUtil(start, n);
    printf("\n");
}

// Main function
int main() {
    int vertices, edges;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(start, vertices);
    dfs(start, vertices);

    return 0;
}
