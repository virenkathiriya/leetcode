/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* root, int d, int v, int depth, bool isLeft) {
        if (d > depth) return NULL;
        if (d == depth) {
            TreeNode* replacement = new TreeNode(v);
            (isLeft) ? replacement -> left = root : replacement -> right = root;
            return replacement;
        } 
        if (!root) return root;
        root -> left = dfs(root -> left, d + 1, v, depth, true);
        root -> right = dfs(root -> right, d + 1, v, depth, false);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return dfs(root, 1, val, depth, true);
    }
};