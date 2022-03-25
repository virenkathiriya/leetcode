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
    long long prev = LLONG_MIN; 
    bool valid = true;
    void dfs(TreeNode* root) {
        if(root && valid) {
            dfs(root -> left);
            if (root -> val <= prev)  {
                valid = false;
                return;
            }
            prev = root -> val;
            dfs(root -> right);
        }
    }
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        dfs(root);
        return valid;
    }
};