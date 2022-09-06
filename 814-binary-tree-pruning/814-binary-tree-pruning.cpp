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
    bool dfs(TreeNode* root) {
        if (!root) return false;
        
        bool l = dfs(root -> left);
        bool r = dfs(root -> right);
        if (root -> val != 1 && !l && !r) {
            root = NULL;
            return false;
        }
        if (!l) root -> left = NULL;
        if (!r) root -> right = NULL;
        return true;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if (!dfs(root)) root = NULL;
        return root;
    }
};