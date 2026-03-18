#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int visited[n];  // to mark whether an element is already counted
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == 1) continue;  // skip if already counted

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1;  // mark duplicate as counted
            }
        }
        printf("%d:%d ", arr[i], count);
    }

    printf("\n");
    return 0;
}
