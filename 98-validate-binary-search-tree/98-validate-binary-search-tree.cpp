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
    bool isValidBST(TreeNode* root, long mx = LONG_MAX, long mn = LONG_MIN) {
        if (!root) return true;
        if (root -> val >= mx || root -> val <= mn) return false;
        return isValidBST(root -> left, root -> val, mn) && isValidBST(root -> right, mx, root -> val);
    }
};