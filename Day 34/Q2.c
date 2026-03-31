int calculate(char* s) {
    int len = strlen(s);
    int stack[len];   // stack to store intermediate results
    int top = -1;
    int num = 0;
    char op = '+';    // default operator

    for (int i = 0; i < len; i++) {
        char c = s[i];

        if (isdigit(c)) {
            num = num * 10 + (c - '0');  // build number
        }

        if ((!isdigit(c) && !isspace(c)) || i == len - 1) {
            if (op == '+') {
                stack[++top] = num;
            } else if (op == '-') {
                stack[++top] = -num;
            } else if (op == '*') {
                stack[top] = stack[top] * num;
            } else if (op == '/') {
                stack[top] = stack[top] / num;  // truncates toward zero in C
            }
            op = c;
            num = 0;
        }
    }

    int result = 0;
    for (int i = 0; i <= top; i++) {
        result += stack[i];
    }
    return result;
}

