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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q[2];
        q[0].push(root);
        vector<vector<int>> ans;
        while (!q[0].empty() || !q[1].empty()) {
            vector<int> t;
            int bit = !q[0].empty() ? 0 : 1;
            while(!q[bit].empty()) {
                TreeNode *cur = q[bit].front();
                q[bit].pop();
                t.push_back(cur -> val);
                if (cur -> left) q[bit ^ 1].push(cur -> left);
                if (cur -> right) q[bit ^ 1].push(cur -> right);
            }
            ans.push_back(t);
        }
        return ans;
    }
};