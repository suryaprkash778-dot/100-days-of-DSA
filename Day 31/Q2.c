bool isValid(char * s) {
    int len = strlen(s);
    char stack[len];   // stack to hold opening brackets
    int top = -1;      // stack pointer

    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;  // push opening bracket
        } else {
            if (top == -1) return false;  // no matching opening bracket
            char topChar = stack[top--];  // pop from stack
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false;  // mismatch
            }
        }
    }
    return top == -1;  // valid if stack is empty
}
