/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            
            // Check if there is a cycle
            if (slow == fast) {
                break;
            }
        }

        // If there is no cycle
        if (fast == NULL || fast->next == NULL) {
            return NULL;
        }

        // Move one pointer to the beginning and keep the other at the meeting point
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};