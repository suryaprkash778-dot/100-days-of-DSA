#include <stdio.h>
#include <stdlib.h>

// Definition of a node
struct Node {
    int data;
    struct Node* next;
};

// Utility function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create a circular linked list from input array
struct Node* createCircularList(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* head = newNode(arr[0]);
    struct Node* tail = head;

    for (int i = 1; i < n; i++) {
        tail->next = newNode(arr[i]);
        tail = tail->next;
    }

    // Make it circular: last node points to head
    tail->next = head;

    return head;
}

// Function to traverse and print circular linked list
void traverseCircularList(struct Node* head) {
    if (!head) return;

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Driver code
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* head = createCircularList(arr, n);

    traverseCircularList(head);

    return 0;
}
