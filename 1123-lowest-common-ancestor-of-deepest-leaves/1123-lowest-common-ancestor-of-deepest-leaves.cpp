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
    pair<int, TreeNode*> dfs(TreeNode* u, int d) {
        if (!u) return {d, NULL};
        
        auto l = dfs(u -> left, d + 1);
        auto r = dfs(u -> right, d + 1);
        if (l.first == r.first) {
            return {l.first, u};
        } else if (l.first > r.first) {
            return l;
        } 
        return r;
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto it = dfs(root, 0);
        return it.second;
    }
};