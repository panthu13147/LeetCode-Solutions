/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    bool res=true;
    int depth(TreeNode* curr)
        {
            if(curr==nullptr)
            {
                return 0;
            }
            int left=depth(curr->left);
            int right=depth(curr->right);
            if(abs(left-right)>1)
            {
                res=false;
            }
            return  1+max(left,right);

        }
public:
    bool isBalanced(TreeNode* root) {
        int height=0;
        
        depth(root);

        return res;
    }
};