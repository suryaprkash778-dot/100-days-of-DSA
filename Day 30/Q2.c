// Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to add two numbers represented by linked lists (forward order)
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int stack1[101], stack2[101];
    int top1 = -1, top2 = -1;

    // Push all digits of l1 into stack1
    while (l1) {
        stack1[++top1] = l1->val;
        l1 = l1->next;
    }

    // Push all digits of l2 into stack2
    while (l2) {
        stack2[++top2] = l2->val;
        l2 = l2->next;
    }

    int carry = 0;
    struct ListNode* head = NULL;

    // Pop from stacks and add digits
    while (top1 >= 0 || top2 >= 0 || carry) {
        int val1 = (top1 >= 0) ? stack1[top1--] : 0;
        int val2 = (top2 >= 0) ? stack2[top2--] : 0;

        int total = val1 + val2 + carry;
        carry = total / 10;
        int digit = total % 10;

        // Insert new node at front
        struct ListNode* newNode = createNode(digit);
        newNode->next = head;
        head = newNode;
    }

    return head;
}

// Utility function to print linked list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(" ");
        head = head->next;
    }
    printf("\n");
}
