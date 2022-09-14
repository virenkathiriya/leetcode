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
    bool checkIfPalindrome(vector<int> &f) {
        int oddCnt = 0;
        for (int &x: f) if (x % 2) oddCnt++;
        return oddCnt < 2;
    }
    
    void dfs(TreeNode* root, vector<int> &f, int &cnt) {
        if (!root) return;
        f[root -> val]++;
        if (!root -> left && !root -> right) cnt += checkIfPalindrome(f);
        else {
            if (root -> left) dfs(root -> left, f, cnt);
            if (root -> right) dfs(root -> right, f, cnt);
        }
        f[root -> val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> f(10, 0);
        int cnt = 0;
        dfs(root, f, cnt);
        return cnt;
    }
};