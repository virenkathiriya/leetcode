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
    void dfs(TreeNode* node, int sum, vector<int> cur, vector<vector<int>>& ans, int t) {
        if (!node) return;
        sum += node -> val;
        cur.push_back(node -> val);
        
        if (sum == t && isLeaf(node)) {
            ans.push_back(cur);
            return;
        } 
        
        if (node -> left) {
            dfs(node -> left, sum, cur, ans, t);
        } 
        if (node -> right) {
            dfs(node -> right, sum, cur, ans, t);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<vector<int>> ans;
        dfs(root, 0, {}, ans, t);
        return ans;
    }
};