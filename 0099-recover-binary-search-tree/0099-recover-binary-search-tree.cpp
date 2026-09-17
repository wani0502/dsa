class Solution {
private:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {
        if (!root) return;
        
        // Traverse the left subtree
        inorder(root->left);
        
        // Process the current node
        if (prev != nullptr && root->val < prev->val) {
            // If this is the first time we see a violation, 
            // the first swapped node is the previous node.
            // We also tentatively set the second node to the current one 
            // (in case the swapped nodes are adjacent).
            if (first == nullptr) {
                first = prev;
                second = root;
            } else {
                // If it's the second violation, the second swapped node is the current one.
                second = root;
            }
        }
        
        // Update previous node to current before moving to right subtree
        prev = root;
        
        // Traverse the right subtree
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        // Find the two swapped nodes
        inorder(root);
        
        // Swap their values to recover the BST
        if (first && second) {
            std::swap(first->val, second->val);
        }
    }
};