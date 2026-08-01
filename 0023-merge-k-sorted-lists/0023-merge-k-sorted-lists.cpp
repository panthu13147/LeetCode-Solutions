class Solution {
private:
    // Helper function ko bahar alag se define karna padta hai C++ mein
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        
        // C++ mein l1 aur l2 check karte hain, unka next nahi
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        // Bachi hui list ko attach karna
        if (l1 != nullptr) {
            tail->next = l1;
        } else {
            tail->next = l2;
        }
        
        return dummy->next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Python ka 'if not lists' C++ mein 'empty()' hota hai
        if (lists.empty()) {
            return nullptr;
        }

        // Python ka 'lists > 1' C++ mein 'size() > 1' hota hai
        while (lists.size() > 1) {
            vector<ListNode*> mergedList; // Naya khali array
            
            // i+2 likhna padta hai as 'i += 2' C++ mein
            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                
                // Agar i+1 bounds ke bahar hai, toh l2 ko nullptr maan lo
                ListNode* l2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
                
                // Python append() = C++ push_back()
                mergedList.push_back(mergeList(l1, l2)); 
            }
            // Array update kar do agle round ke liye
            lists = mergedList; 
        }

        return lists[0];
    }
};