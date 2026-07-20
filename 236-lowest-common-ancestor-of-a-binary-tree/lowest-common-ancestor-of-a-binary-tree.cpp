class Solution {
public:
    inline TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q)
            return root;

        TreeNode* l = dfs(root->left, p, q);
        TreeNode* r = dfs(root->right, p, q);

        if (l && r) return root;
        return l ? l : r;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};