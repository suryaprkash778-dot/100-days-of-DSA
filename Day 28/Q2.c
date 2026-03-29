// Utility function to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Reverse a linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Check if linked list is palindrome
bool isPalindrome(struct ListNode* head) {
    if (!head || !head->next) return true;

    // Step 1: Find middle using slow/fast pointers
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    struct ListNode* secondHalf = reverseList(slow->next);

    // Step 3: Compare halves
    struct ListNode* p1 = head;
    struct ListNode* p2 = secondHalf;
    bool result = true;
    while (p2) {
        if (p1->val != p2->val) {
            result = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    // Step 4 (optional): Restore list
    slow->next = reverseList(secondHalf);

    return result;
}
