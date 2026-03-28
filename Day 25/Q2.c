struct ListNode* detectCycle(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    // Step 1: Detect cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            // Cycle detected
            break;
        }
    }
    
    // If no cycle
    if (fast == NULL || fast->next == NULL) {
        return NULL;
    }
    
    // Step 2: Find cycle start
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow; // Start of cycle
}

// Helper function to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}
