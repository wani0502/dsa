class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        
        while (curr != nullptr) {
            // If the current node has a left child
            if (curr->left != nullptr) {
                // Find the rightmost node in the left subtree
                TreeNode* runner = curr->left;
                while (runner->right != nullptr) {
                    runner = runner->right;
                }
                
                // Rewire connections: 
                // 1. Point the rightmost node's right to the current node's right
                runner->right = curr->right;
                // 2. Move the entire left subtree to the right
                curr->right = curr->left;
                // 3. Nullify the left child
                curr->left = nullptr;
            }
            
            // Move to the next node on the right
            curr = curr->right;
        }
    }
};