class Solution {
public:
    void dfs(TreeNode* root,int target,vector<int>& path,vector<vector<int>>& ans){
        if(root==NULL) return;
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL) {
            if(target==root->val){
                ans.push_back(path);
            }
            path.pop_back();
            return;
        }
        dfs(root->left,target-root->val,path,ans);
        dfs(root->right,target-root->val,path,ans);
        path.pop_back(); 
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;

        dfs(root, targetSum, path, ans);

        return ans;
    }
};
