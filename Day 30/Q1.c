#include <stdio.h>
#include <stdlib.h>

// Definition for polynomial node
struct PolyNode {
    int coeff;
    int exp;
    struct PolyNode* next;
};

// Function to create a new node
struct PolyNode* createNode(int coeff, int exp) {
    struct PolyNode* node = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    node->coeff = coeff;
    node->exp = exp;
    node->next = NULL;
    return node;
}

// Function to insert node at the end
void insertNode(struct PolyNode** head, int coeff, int exp) {
    struct PolyNode* newNode = createNode(coeff, exp);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct PolyNode* temp = *head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print polynomial in standard form
void printPolynomial(struct PolyNode* head) {
    struct PolyNode* temp = head;
    while (temp) {
        printf("%d", temp->coeff);
        if (temp->exp > 0) {
            printf("x");
            if (temp->exp > 1) {
                printf("^%d", temp->exp);
            }
        }
        if (temp->next) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    struct PolyNode* head = NULL;

    for (int i = 0; i < n; i++) {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);
        insertNode(&head, coeff, exp);
    }

    printPolynomial(head);

    return 0;
}
