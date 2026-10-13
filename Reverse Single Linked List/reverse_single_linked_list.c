struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *nex = NULL;

    while (curr != NULL) {
        nex = curr->next;   // Save next node
        curr->next = prev;  // Reverse link
        prev = curr;        // Move prev forward
        curr = nex;         // Move curr forward
    }

    return prev; // New head of reversed list
}
