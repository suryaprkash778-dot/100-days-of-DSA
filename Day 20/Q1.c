#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hash map node for prefix sums
typedef struct Node {
    long long key;   // prefix sum
    int count;       // frequency
    struct Node* next;
} Node;

#define HASH_SIZE 100003  // large prime for hashing

Node* hashTable[HASH_SIZE];

// Simple hash function
int hashFunc(long long key) {
    if (key < 0) key = -key;
    return (int)(key % HASH_SIZE);
}

// Insert or update prefix sum in hash table
void insert(long long key, int* totalCount) {
    int h = hashFunc(key);
    Node* cur = hashTable[h];
    while (cur) {
        if (cur->key == key) {
            *totalCount += cur->count;  // each previous occurrence forms a zero-sum subarray
            cur->count++;
            return;
        }
        cur = cur->next;
    }
    // not found, create new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->count = 1;
    newNode->next = hashTable[h];
    hashTable[h] = newNode;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    memset(hashTable, 0, sizeof(hashTable));

    long long prefix = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        prefix += arr[i];
        if (prefix == 0) count++;  // subarray from start to i
        insert(prefix, &count);
    }

    printf("%d\n", count);
    return 0;
}
