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
        ListNode* curr = head;
        ListNode* ahead = head;
        if(head==nullptr || head -> next == nullptr)
        {
            return nullptr;
        }
        
        for(int i=0;i<n;i++)
        {
            ahead = ahead -> next;
            if(ahead == nullptr)
            {
                return head = head -> next;
            }
        }
        while(ahead != nullptr && ahead -> next != nullptr)
        {
            ahead = ahead -> next;
            curr = curr -> next;

        }
        
        ListNode* temp = curr->next->next;
        curr ->next = temp;
        
        return head;
    }
};