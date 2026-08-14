/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    // 1. Global map aur index tracker
    unordered_map<int, int> inorder_map;
    int preorder_idx = 0;

public:
    // Yeh main function hai jo LeetCode call karega
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Hash map mein saare (value -> index) store kar lo
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }
        
        // Helper function ko call karo initial boundaries ke saath (0 to size-1)
        return build(preorder, inorder, 0, inorder.size() - 1);
    }

private:
    // Yeh tera asli Recursive Helper Function hai
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int left, int right) {
        // Base condition: Boundary invalid ho gayi
        if (left > right) {
            return nullptr;
        }

        // 1. Preorder se Naya node banao
        int root_val = preorder[preorder_idx++];
        TreeNode* root = new TreeNode(root_val);

        // 2. Us element ka index dhoondho Inorder array mein
        int mid = inorder_map[root_val];

        // 3. Pointers (left, right) change karke Left aur Right Subtrees build karo
        root->left = build(preorder, inorder, left, mid - 1);  // Left ka naya right end 'mid - 1' ban gaya
        root->right = build(preorder, inorder, mid + 1, right); // Right ka naya left start 'mid + 1' ban gaya
        
        return root;
    }
};