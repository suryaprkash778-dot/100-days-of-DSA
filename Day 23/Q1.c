#include <stdio.h>
#include <stdlib.h>

// Definition of linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert node at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* node = newNode(data);
    if (head == NULL) return node;
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
    return head;
}

// Merge two sorted linked lists
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    struct Node* result = NULL;
    struct Node** lastPtrRef = &result;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            *lastPtrRef = l1;
            l1 = l1->next;
        } else {
            *lastPtrRef = l2;
            l2 = l2->next;
        }
        lastPtrRef = &((*lastPtrRef)->next);
    }

    if (l1 != NULL) *lastPtrRef = l1;
    else *lastPtrRef = l2;

    return result;
}

// Print linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, m, val;
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Input first list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        list1 = insertEnd(list1, val);
    }

    // Input second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        list2 = insertEnd(list2, val);
    }

    // Merge and print result
    struct Node* merged = mergeLists(list1, list2);
    printList(merged);

    return 0;
}
