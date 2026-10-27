/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Detect if a cycle exists
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Find the start of the cycle
            struct ListNode *entry = head;

            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }

            return entry;
        }
    }

    return NULL;
}
