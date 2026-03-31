#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node structure for stack
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Push onto stack
void push(Node** top, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop from stack
int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    }
    Node* temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

// Evaluate postfix expression
int evaluatePostfix(char* expr) {
    Node* stack = NULL;
    char* token = strtok(expr, " ");

    while (token != NULL) {
        // If operand, push to stack
        if (isdigit(token[0]) || 
            (strlen(token) > 1 && isdigit(token[1]))) { // handles negative numbers
            push(&stack, atoi(token));
        } else {
            // Operator: pop two operands
            int b = pop(&stack);
            int a = pop(&stack);
            int result;

            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break; // truncates toward zero
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
            push(&stack, result);
        }
        token = strtok(NULL, " ");
    }

    return pop(&stack);
}

// Example usage
int main() {
    char expr[] = "2 3 1 * + 9 -";  // Example input
    int result = evaluatePostfix(expr);
    printf("Output: %d\n", result); // Expected: -4
    return 0;
}
