int hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return 0; // false
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head->next;

    while (slow != fast) {
        if (fast == NULL || fast->next == NULL) {
            return 0; // false
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    return 1; // true
}

// Helper function to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}
