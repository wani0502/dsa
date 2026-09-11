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
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        int l=maxDepth(root->left);
        int r=maxDepth(root->right);
        return 1+max(r,l);
    }
    bool isBalanced(TreeNode* root) {
       if(root==nullptr) return true;
       int lh=maxDepth(root->left);
       int rh=maxDepth(root->right);
       if(abs(lh-rh)<=1&& isBalanced(root->left) && isBalanced(root->right)) return true;
       return false; 
    }
};