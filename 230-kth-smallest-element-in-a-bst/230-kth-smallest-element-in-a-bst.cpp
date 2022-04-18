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
    int ans = -1, cnt = 0;
    int kthSmallest(TreeNode* root, int k) {
        f(root, k);
        return ans;
    }
    
    void f(TreeNode* u, int &k) {
        if (u) {
            f(u -> left, k);
            cnt++;
            if (cnt == k) ans = u -> val;
            f(u -> right, k);
        }
    }
};