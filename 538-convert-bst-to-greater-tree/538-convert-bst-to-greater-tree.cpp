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
    int f(TreeNode* u, int sum) {
        if(!u) return sum;
        u -> val += f(u -> right, sum);
        return f (u -> left, u -> val);
    }
    TreeNode* convertBST(TreeNode* root) {
        f (root, 0);
        return root;
    }
};