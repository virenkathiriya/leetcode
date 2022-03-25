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
    map<int, bool> mp;
    bool ok = false;
    void dfs(TreeNode* root, int k) {
        if(!root) return;
        dfs(root -> left, k);
        if(mp[k - root -> val]) {
            ok = true;
            return;
        }
        mp[root -> val] = true;
        dfs(root -> right, k);
    } 
    bool findTarget(TreeNode* root, int k) {
        dfs(root, k);
        return ok;
    }
};