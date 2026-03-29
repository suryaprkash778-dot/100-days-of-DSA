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

// Function to calculate length of a linked list
int getLength(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to find intersection point
struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Advance pointer in longer list
    if (len1 > len2) {
        while (diff--) head1 = head1->next;
    } else {
        while (diff--) head2 = head2->next;
    }

    // Traverse both lists together
    while (head1 && head2) {
        if (head1 == head2) return head1; // intersection found
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL; // no intersection
}

int main() {
    int n, m;
    scanf("%d", &n);

    struct Node* head1 = NULL;
    struct Node* tail1 = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* node = newNode(val);
        if (!head1) head1 = node;
        else tail1->next = node;
        tail1 = node;
    }

    scanf("%d", &m);
    struct Node* head2 = NULL;
    struct Node* tail2 = NULL;

    for (int i = 0; i < m; i++) {
        int val;
        scanf("%d", &val);
        struct Node* node = newNode(val);
        if (!head2) head2 = node;
        else tail2->next = node;
        tail2 = node;
    }

    // For demonstration: manually create intersection
    // In real input, intersection must be created by sharing nodes
    // Example: attach tail2->next to some node in list1
    // Here, we simulate intersection at node with value 30
    struct Node* temp = head1;
    while (temp && temp->data != 30) temp = temp->next;
    if (temp) tail2->next = temp;

    struct Node* intersect = getIntersection(head1, head2);
    if (intersect) printf("%d\n", intersect->data);
    else printf("No Intersection\n");

    return 0;
}
