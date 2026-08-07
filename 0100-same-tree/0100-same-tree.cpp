class Solution {
public:
    // Yahi hamara DFS function hai!
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        // Base Case 1: Agar dono khali hain, toh exactly same hain (True)
        if (p == nullptr && q == nullptr) {
            return true;
        }
        
        // Base Case 2: Agar ek khali hai aur dusra nahi, YA dono ke numbers alag hain (False)
        if (p == nullptr || q == nullptr || p->val != q->val) {
            return false;
        }
        
        // Recursion: Agar dono current node same hain, toh unke left aur right bacchon ko check karo
        // Dhyan se dekh, main isSameTree ko hi wapas call kar raha hu!
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};