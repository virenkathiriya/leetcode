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
    void dfs(TreeNode *node, vector<int> &path, int cur_sum, vector<vector<int>>& ans, int target) {
        if(node) {
            int val = node -> val;
            path.push_back(val);
            if (cur_sum + val == target && !node -> left && !node -> right) {
                ans.push_back(path);
                path.pop_back();
                return;
            } 
            dfs(node -> left, path, cur_sum + val, ans, target);
            dfs(node -> right, path, cur_sum + val, ans, target);
            path.pop_back();
        }  
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root, path, 0, ans, targetSum);
        return ans;
    }
};