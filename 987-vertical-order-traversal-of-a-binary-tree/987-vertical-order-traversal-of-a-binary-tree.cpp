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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};
        map<int, vector<int>> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            map<int, vector<int>> tmp;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                pair<TreeNode*, int> u = q.front();
                q.pop();
                tmp[u.second].emplace_back(u.first -> val);
                if (u.first -> left) q.push({u.first -> left, u.second - 1});
                if (u.first -> right) q.push({u.first -> right, u.second + 1});
            }
            for (auto it: tmp) {
                sort(it.second.begin(), it.second.end());
                mp[it.first].insert(mp[it.first].end(), it.second.begin(), it.second.end());
            }
        }
        vector<vector<int>> ans;
        for (auto it: mp) ans.push_back(it.second);
        return ans;
    }
};