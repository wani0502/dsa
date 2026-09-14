class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN,LONG_MAX);
    }
    
private:
    bool validate(TreeNode* root,long long low, long long high) {
        if (root == nullptr) {
            return true;
        }
        
        if(root->val>=high||root->val<=low){
            return false;
        }
        return validate(root->left, low, root->val) && 
               validate(root->right, root->val, high);
    }
};