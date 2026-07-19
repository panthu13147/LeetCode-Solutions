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
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* list = head;
        while( list != nullptr && list->next!=nullptr)
        {
            ListNode* Next = list->next;
            if(list->val == Next->val)
            {
                list->next = Next->next;
            }
            else
            {
                list = Next;
            }
        }

        return head;
        
    }
};