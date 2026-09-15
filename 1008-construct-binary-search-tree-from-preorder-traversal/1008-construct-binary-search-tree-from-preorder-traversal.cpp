class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()) return nullptr;
        
        stack<TreeNode*> st;
        // 1. Create the root and push it
        TreeNode* root = new TreeNode(preorder[0]);
        st.push(root);
        
        for(int i = 1; i < preorder.size(); i++){
            TreeNode* node = new TreeNode(preorder[i]);
            
            // 2. If smaller, it belongs to the left of the top node
            if(preorder[i] < st.top()->val){
                st.top()->left = node;
            } 
            // 3. If greater, find the correct parent by popping
            else {
                TreeNode* parent = nullptr;
                while(!st.empty() && st.top()->val < preorder[i]){
                    parent = st.top();
                    st.pop();
                }
                // Attach it to the right of the last popped node
                parent->right = node;
            }
            // 4. Always push the newly created node
            st.push(node);
        }
        
        // 5. Don't forget to return!
        return root;
    }
};