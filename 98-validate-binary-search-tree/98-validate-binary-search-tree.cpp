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
    bool isValidBST(TreeNode* root, long long high = LLONG_MAX, long long low = LLONG_MIN) {
        if (!root) return true;
        int x = root -> val;
        if (x < high && x > low) {
            return isValidBST(root -> left, x, low) && isValidBST(root -> right, high, x);
        }
        return false;
    }
};