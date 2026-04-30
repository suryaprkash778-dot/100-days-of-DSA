int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    bool visited[isConnectedSize];
    for (int i = 0; i < isConnectedSize; i++) {
        visited[i] = false;
    }

    // DFS helper
    void dfs(int city) {
        visited[city] = true;
        for (int j = 0; j < isConnectedSize; j++) {
            if (isConnected[city][j] == 1 && !visited[j]) {
                dfs(j);
            }
        }
    }

    int provinces = 0;
    for (int i = 0; i < isConnectedSize; i++) {
        if (!visited[i]) {
            dfs(i);
            provinces++;
        }
    }
    return provinces;
}
