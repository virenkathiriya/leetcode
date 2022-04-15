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
    void f(TreeNode* root, int l, vector<int> &ans) {
        if (!root) return;
        
        if (ans.size() == l) ans.push_back(root -> val);
        else ans[l] = root -> val;
        
        f (root -> left, l + 1, ans);
        f (root -> right, l + 1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        f (root, 0, ans);
        return ans;
    }
};