class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;

        // The Mega-Condition handles uneven lists AND the lingering carry!
        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            int sum = carry;

            // Safely add l1 if it exists and move pointer
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            // Safely add l2 if it exists and move pointer
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Your exact math!
            int digit = sum % 10;
            carry = sum / 10;

            // Wire up the new node and move forward
            curr->next = new ListNode(digit);
            curr = curr->next;
        }

        ListNode* result = dummy->next;
        delete dummy; // Good practice to clean up memory
        return result;
    }
};