struct NodeInfo {
    bool isBST;
    int minVal;
    int maxVal;
    int sum;
};
class Solution {
private:
    int maxSum = 0;
    NodeInfo postOrder(TreeNode* root) {
        if (!root) {
            return {true, INT_MAX, INT_MIN, 0};
        }
        NodeInfo left = postOrder(root->left);
        NodeInfo right = postOrder(root->right);
        if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
            int currentSum = root->val + left.sum + right.sum;
            maxSum = max(maxSum, currentSum);        
            return {
                true, 
                min(root->val, left.minVal), 
                max(root->val, right.maxVal), 
                currentSum
            };
        }
        return {false, 0, 0, 0};
    }

public:
    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        postOrder(root);
        return maxSum;
    }
};