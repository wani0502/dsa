class Solution {
public:
    bool hasPathSum(TreeNode* root, int target) {
        if(root == NULL)
          return false;
        if(root->left==NULL && root->right==NULL) {
            return target==root->val;
        }
        return hasPathSum(root->left,target-root->val) || hasPathSum(root->right,target-root->val);
    }
};