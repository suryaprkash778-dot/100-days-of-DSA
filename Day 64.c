#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int r, c, t; // row, col, time
} Node;

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    Node queue[m * n];
    int front = 0, rear = 0;

    int freshCount = 0;
    int maxTime = 0;

    // Initialize queue with all rotten oranges
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                queue[rear++] = (Node){i, j, 0};
            } else if (grid[i][j] == 1) {
                freshCount++;
            }
        }
    }

    // Directions: up, down, left, right
    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    // BFS
    while (front < rear) {
        Node cur = queue[front++];
        for (int d = 0; d < 4; d++) {
            int nr = cur.r + dirs[d][0];
            int nc = cur.c + dirs[d][1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                grid[nr][nc] = 2; // rot it
                freshCount--;
                queue[rear++] = (Node){nr, nc, cur.t + 1};
                maxTime = cur.t + 1;
            }
        }
    }

    return freshCount == 0 ? maxTime : -1;
}
