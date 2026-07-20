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
    ListNode* removeElements(ListNode* head, int val) {
       
        int target = val;

        ListNode* dummy = new ListNode();
        dummy ->next = head;
        ListNode* prev = dummy;
        if( head == nullptr )
        {
            return head;
        }

        ListNode* list = head;
        
        while( prev->next != nullptr)
        {
            if( list->val == target)
            {
                prev->next = list->next;
            }
            else
            {

                prev=prev->next;
            }
                            list = list->next;

        }
        



        return dummy->next;



        
    }
};