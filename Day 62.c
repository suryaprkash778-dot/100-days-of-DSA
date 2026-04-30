#include <stdbool.h>

// DFS helper
void dfs(int** rooms, int* roomsColSize, int n, int room, bool* visited) {
    visited[room] = true;
    for (int i = 0; i < roomsColSize[room]; i++) {
        int next = rooms[room][i];
        if (!visited[next]) {
            dfs(rooms, roomsColSize, n, next, visited);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool visited[roomsSize];
    for (int i = 0; i < roomsSize; i++) {
        visited[i] = false;
    }

    dfs(rooms, roomsColSize, roomsSize, 0, visited);

    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) return false;
    }
    return true;
}
