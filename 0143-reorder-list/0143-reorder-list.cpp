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
    void reorderList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr)
        {
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* start = head;

        while(fast != nullptr && fast ->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

        }
        ListNode* prev = nullptr;
        ListNode* second =slow -> next;
        slow -> next = nullptr;
        while(second != nullptr)
        {
          ListNode* next = second -> next;
          second -> next = prev;
          prev = second;
          second = next;
        }
        while( prev != nullptr)
        {
            ListNode* tmp1 = start-> next;
            ListNode* tmp2 = prev -> next;
            start -> next = prev;
            prev ->next = tmp1;
            prev = tmp2;
            start = tmp1; 
            
        }

        return ;





        
    }
};