int evalRPN(char **tokens, int tokensSize) {
    int stack[tokensSize];  // stack to hold operands
    int top = -1;           // stack pointer

    for (int i = 0; i < tokensSize; i++) {
        char *t = tokens[i];

        // Check if current token is an operator
        if (strcmp(t, "+") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a + b;
        } else if (strcmp(t, "-") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a - b;
        } else if (strcmp(t, "*") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a * b;
        } else if (strcmp(t, "/") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a / b;  // truncates toward zero in C
        } else {
            // Operand: convert string to integer
            stack[++top] = atoi(t);
        }
    }

    return stack[top];
}

