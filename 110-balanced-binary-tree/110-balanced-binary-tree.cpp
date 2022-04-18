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
    bool ans = true;
    int f(TreeNode* u) {
        if (!u) return 0;    
        int l = f(u -> left);
        int r = f(u -> right);
        ans &= (abs(r - l) <= 1);
        return max(l, r) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        f(root);
        return ans;
    }
};