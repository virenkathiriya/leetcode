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
    bool ok = false;
    void f(TreeNode* root, int cur, int t) {
        if (!root) return;
        cur += root -> val;
        if (cur == t && (!root -> left && !root -> right)) {ok = true; return;}
        f(root -> left, cur, t);
        f(root -> right, cur, t);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        f(root, 0, targetSum);
        return ok;
    }
};