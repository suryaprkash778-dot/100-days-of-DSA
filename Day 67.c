#include <stdbool.h>
#include <stdlib.h>

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    // adjacency list
    int** graph = malloc(numCourses * sizeof(int*));
    int* graphColSize = calloc(numCourses, sizeof(int));
    for (int i = 0; i < numCourses; i++) {
        graph[i] = malloc(prerequisitesSize * sizeof(int)); // max possible edges
        graphColSize[i] = 0;
    }

    // indegree array
    int* indegree = calloc(numCourses, sizeof(int));

    // build graph
    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int prereq = prerequisites[i][1];
        graph[prereq][graphColSize[prereq]++] = course;
        indegree[course]++;
    }

    // queue for BFS
    int* queue = malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;

    // start with courses having indegree 0
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int* order = malloc(numCourses * sizeof(int));
    int idx = 0;

    while (front < rear) {
        int cur = queue[front++];
        order[idx++] = cur;
        for (int j = 0; j < graphColSize[cur]; j++) {
            int next = graph[cur][j];
            indegree[next]--;
            if (indegree[next] == 0) {
                queue[rear++] = next;
            }
        }
    }

    if (idx == numCourses) {
        *returnSize = numCourses;
        return order;
    } else {
        *returnSize = 0;
        return NULL; // cycle detected
    }
}
