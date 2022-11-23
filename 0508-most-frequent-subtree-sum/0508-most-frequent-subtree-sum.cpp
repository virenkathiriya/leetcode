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
    int mx = 0;
    
    int f(TreeNode* root) {
        if (!root) return 0;
        
        int l = f(root -> left), r = f(root -> right);
        int sum = l + r + root -> val;
        mp[sum]++;
        mx = max(mx, mp[sum]);
        return sum;
    }
        
    vector<int> findFrequentTreeSum(TreeNode* root) {
        f(root);
        vector<int> ans;
        for (auto &it: mp) {
            if (it.second == mx) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};