/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || n <= 0) {
            return head; // No need to remove if the list is empty or n is not valid.
        }

        // Create a dummy node to handle the case of removing the head node.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Move the first pointer n nodes ahead.
        for (int i = 0; i < n; i++) {
            if (first == nullptr) {
                delete dummy; // Clean up the dummy node.
                return head; // N is greater than the length of the list. No need to remove.
            }
            first = first->next;
        }

        // Move both pointers until first reaches the end.
        while (first->next) {
            first = first->next;
            second = second->next;
        }

        // Remove the Nth node by updating the next pointer.
        ListNode* temp = second->next;
        second->next = temp->next;
        delete temp;

        ListNode* newHead = dummy->next; // Store the new head.

        delete dummy; // Clean up the dummy node.

        return newHead;
    }
};
