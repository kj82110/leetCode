/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> parent;
        stack<TreeNode*> st;

        parent[root] = nullptr;
        st.push(root);

        while (!parent.count(p) || !parent.count(q)) {
            TreeNode* node = st.top();
            st.pop();

            if (node->left) {
                parent[node->left] = node;
                st.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                st.push(node->right);
            }
        }

        unordered_set<TreeNode*> ancestors;

        while (p) {
            ancestors.insert(p);
            p = parent[p];
        }

        while (!ancestors.count(q))
            q = parent[q];

        return q;
    }
};