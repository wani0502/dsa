class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mp;
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, 0});
        while (!q.empty()) {
            auto [node, row, col] = q.front();
            q.pop();
            if (node == nullptr) {
                continue;
            }
            mp[col].push_back({row, node->val});
            q.push({node->left, row + 1, col - 1});
            q.push({node->right, row + 1, col + 1});
        }
        vector<vector<int>> ans;
        for (auto &entry : mp) {
            auto &v = entry.second;
            sort(v.begin(), v.end(), [](auto &a, auto &b) {
                if (a.first != b.first)
                    return a.first < b.first;

                return a.second < b.second;
            });
            vector<int> column;
            for (auto &p : v) {
                column.push_back(p.second);
            }
            ans.push_back(column);
        }
        return ans;
    }
};