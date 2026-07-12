class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 1. Create a dummy node that points to the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // 2. Both pointers start at the dummy
        ListNode* curr = dummy;
        ListNode* ahead = dummy;
        
        // 3. Create the gap of n + 1 (so curr stops right before the target)
        for(int i = 0; i <= n; i++) {
            ahead = ahead->next;
        }
        
        // 4. Move both until ahead falls off the end
        while(ahead != nullptr) {
            ahead = ahead->next;
            curr = curr->next;
        }
        
        // 5. Delete the nth node
        ListNode* temp = curr->next;
        curr->next = curr->next->next;
        delete temp; // Good C++ practice to prevent memory leaks!
        
        // 6. Return the true head (which is safe even if the original head was deleted)
        ListNode* newHead = dummy->next;
        delete dummy; 
        
        return newHead;
    }
};