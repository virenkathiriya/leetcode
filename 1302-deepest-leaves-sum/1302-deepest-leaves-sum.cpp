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
    map<int, int> mp;
    void f(TreeNode* root, int l) {
        if(root) {
            if (!root -> left && !root -> right) {
                mp[l] += root -> val;
                return;
            }
            f(root -> left, l + 1);
            f(root -> right, l + 1);
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        f(root, 0);
        return (*mp.rbegin()).second;
    }
};