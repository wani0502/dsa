class Solution {
public:
    void find(TreeNode* root, int k, vector<int>& ans) {
        if (root == nullptr || k < 0)
            return;
        if (k == 0) {
            ans.push_back(root->val);
            return;
        }
        find(root->left, k - 1, ans);
        find(root->right, k - 1, ans);
    }
    void dfs(TreeNode* root, TreeNode* target, int k,
        int& distance, bool& found, vector<int>& ans) {
        if (root == nullptr)
            return;
        if (root == target) {
            found = true;
            distance = 0;
            find(root, k, ans); 
            return;
        }
        dfs(root->left, target, k, distance, found, ans);
        if (found) {
            distance++; 
            if (distance == k)
                ans.push_back(root->val);
            find(root->right, k - distance - 1, ans);
            return;
        }
        dfs(root->right, target, k, distance, found, ans);
        if (found) {
            distance++; 
            if (distance == k)
                ans.push_back(root->val);
            find(root->left, k - distance - 1, ans);
            return;
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        bool found = false;
        int distance = 0;
        dfs(root, target, k, distance, found, ans);
        return ans;
    }
};