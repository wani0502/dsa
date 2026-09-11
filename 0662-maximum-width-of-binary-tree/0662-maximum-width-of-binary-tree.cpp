class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        unsigned long long maxWidth = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            int size = q.size();
            unsigned long long start = q.front().second;
            unsigned long long end = start;
            
            for (int i = 0; i < size; ++i) {
                auto [node, idx] = q.front();
                q.pop();
               
                unsigned long long cur_id = idx - start; 
                end = cur_id;
                
                if (node->left) {
                    q.push({node->left, cur_id * 2 + 1});
                }
                if (node->right) {
                    q.push({node->right, cur_id * 2 + 2});
                }
            }
            
            maxWidth = max(maxWidth, end + 1);
        }
        
        return maxWidth;
    }
};