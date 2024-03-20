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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
   ListNode* dummy = new ListNode(); // Dummy head for result linked list
        ListNode* current = dummy; // Pointer to current node in result linked list
        int carry = 0; // Initialize carry to 0
        
        // Traverse both linked lists until both are exhausted
        while (l1 || l2) {
            // Add values of current nodes along with carry from previous step
            int sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            // Update carry for next step
            carry = sum / 10;
            // Create a new node with the sum modulo 10
            current->next = new ListNode(sum % 10);
            // Move to the next nodes in both linked lists if they exist
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            current = current->next; // Move to the next node in result linked list
        }
        
        // If there's still a carry after both lists are exhausted, create an additional node
        if (carry > 0) {
            current->next = new ListNode(carry);
        }
        
        return dummy->next; // Return the next node after the dummy head
    }
};