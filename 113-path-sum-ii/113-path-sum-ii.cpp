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
    bool isLeaf(TreeNode* node) {
        return node && !node -> left && !node -> right;
    }
    
    void dfs(TreeNode* node, int sum, vector<int>& cur, vector<vector<int>>& ans, int t) {
        if (node) {
            sum += node -> val;
            cur.push_back(node -> val);
        
            if (sum == t && isLeaf(node)) {
                ans.push_back(cur);
            } else {
                dfs(node -> left, sum, cur, ans, t);
                dfs(node -> right, sum, cur, ans, t);
            }
            cur.pop_back();
        }
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(root, 0, cur, ans, t);
        return ans;
    }
};