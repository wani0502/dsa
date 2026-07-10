class Solution {
public:
    TreeNode* build(vector<int>& inorder,
                    int is,
                    int ie,
                    vector<int>& postorder,
                    int ps,
                    int pe,
                    map<int,int>& hm){

        if(ps > pe || is > ie)
            return NULL;

        TreeNode* root = new TreeNode(postorder[pe]);

        int in_root = hm[root->val];
        int nums_left = in_root - is;

        root->left = build(
            inorder,
            is,
            in_root - 1,
            postorder,
            ps,
            ps + nums_left - 1,
            hm
        );

        root->right = build(
            inorder,
            in_root + 1,
            ie,
            postorder,
            ps + nums_left,
            pe - 1,
            hm
        );

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder,
                        vector<int>& postorder) {

        map<int,int> hm;

        for(int i = 0; i < inorder.size(); i++)
            hm[inorder[i]] = i;

        return build(
            inorder,
            0,
            inorder.size() - 1,
            postorder,
            0,
            postorder.size() - 1,
            hm
        );
    }
};