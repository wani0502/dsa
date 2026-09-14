class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }
    
private:
    bool validate(TreeNode* node, TreeNode* low, TreeNode* high) {
        // Base case: empty trees are valid BSTs
        if (node == nullptr) {
            return true;
        }
        
        // The current node's value must be strictly between the low and high bounds
        if ((low != nullptr && node->val <= low->val) || 
            (high != nullptr && node->val >= high->val)) {
            return false;
        }
        
        // Recursively validate left and right subtrees
        // For the left subtree, the current node becomes the upper bound (high)
        // For the right subtree, the current node becomes the lower bound (low)
        return validate(node->left, low, node) && 
               validate(node->right, node, high);
    }
};