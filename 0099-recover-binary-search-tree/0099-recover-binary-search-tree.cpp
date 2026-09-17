class Solution {
private:
    TreeNode* first = nullptr;
    TreeNode* middle = nullptr;
    TreeNode* last= nullptr;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);  
        if (last != nullptr && root->val < last->val) {  
            if (first == nullptr) {
                first = last;
                middle= root;
            } else {    
                middle= root;
            }
        }   
        last = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        if (first && middle) {
            std::swap(first->val, middle->val);
        }
    }
};