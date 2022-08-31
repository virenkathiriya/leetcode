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
    long long cnt = 0;
    
    void dfs(TreeNode* root, unordered_map<long long, long long> &mp, long long sum, long long target) {
        if (root) {
            cnt += mp[sum + root -> val - target];
            sum += root -> val;
            mp[sum]++;
            
            dfs(root -> left, mp, sum, target);
            dfs(root -> right, mp, sum, target);
            mp[sum]--;
        }
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, long long> mp;
        mp[0] = 1;
        dfs(root, mp, 0, targetSum);
        return cnt;
    }
};