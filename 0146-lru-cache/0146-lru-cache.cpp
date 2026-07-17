class LRUCache {
private:
    // 1. Struct jisme key aur value dono hain
    struct ListNode {
        int key;
        int val;
        ListNode* prev;
        ListNode* next;
        ListNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    unordered_map<int, ListNode*> map;
    ListNode* dummy = new ListNode(-1, -1); // Head
    ListNode* tail = new ListNode(-1, -1);  // Tail
    int n;

    void addnode(ListNode* newnode) {
        ListNode* nextNode = dummy->next;
        newnode->next = nextNode;
        newnode->prev = dummy;
        dummy->next = newnode;
        nextNode->prev = newnode;
    }

    void delnode(ListNode* delnode) {
        ListNode* prevNode = delnode->prev;
        ListNode* nextNode = delnode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int capacity) {
        n = capacity;
        dummy->next = tail;
        tail->prev = dummy;
    }
    
    int get(int key) {
        if (map.find(key) != map.end()) {
            ListNode* resNode = map[key];
            int ans = resNode->val;
            
            // Item use hua, toh usko list mein most recent (front) pe lao
            map.erase(key);       // Purana pointer map se hatao
            delnode(resNode);     // List se uski purani position se hatao
            addnode(resNode);     // Head ke baad naya add karo
            map[key] = dummy->next; // Map mein nayi position update karo
            
            return ans;
        }
        return -1; // Agar nahi mila
    }
    
    void put(int key, int value) {
        // CASE 1: Agar key pehle se exist karti hai
        if (map.find(key) != map.end()) {
            ListNode* existingNode = map[key];
            map.erase(key);
            delnode(existingNode);
        } 
        // CASE 2: Agar capacity full ho chuki hai
        else if (map.size() == n) {
            ListNode* lruNode = tail->prev; // Sabse purana (Least Recent) node
            map.erase(lruNode->key); // Isiliye struct mein key store ki thi!
            delnode(lruNode);
        }
        
        // CASE 3: Naya node front (most recent) par add karo
        addnode(new ListNode(key, value));
        map[key] = dummy->next;
    }
};