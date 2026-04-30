#include <stdbool.h>

bool dfs(int** graph, int* graphColSize, int node, int* visited) {
    if (visited[node] == 1) return true;   // cycle detected
    if (visited[node] == 2) return false;  // already processed

    visited[node] = 1; // mark as visiting
    for (int i = 0; i < graphColSize[node]; i++) {
        int next = graph[node][i];
        if (dfs(graph, graphColSize, next, visited)) return true;
    }
    visited[node] = 2; // mark as visited
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    // Build adjacency list
    int* graphColSize = calloc(numCourses, sizeof(int));
    int** graph = malloc(numCourses * sizeof(int*));
    for (int i = 0; i < numCourses; i++) {
        graph[i] = malloc(prerequisitesSize * sizeof(int)); // max possible edges
        graphColSize[i] = 0;
    }

    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int prereq = prerequisites[i][1];
        graph[prereq][graphColSize[prereq]++] = course;
    }

    int* visited = calloc(numCourses, sizeof(int)); // 0=unvisited, 1=visiting, 2=visited

    for (int i = 0; i < numCourses; i++) {
        if (visited[i] == 0) {
            if (dfs(graph, graphColSize, i, visited)) return false;
        }
    }
    return true;
}
