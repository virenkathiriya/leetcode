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
    void f(TreeNode* root, string s, vector<string>&ans) {
        if (!root) {
            if (s.length() > 0) {
                ans.push_back(s);
            }
            return;
        }
        string t = s;
        s += ((s.size() > 0) ? "->": "") + to_string(root -> val);
        if (!root -> left && !root -> right) {
            ans.push_back(s);
        } else if (!root -> left) {
            f (root -> right, s, ans);
        } else if (!root -> right){
            f (root -> left, s, ans);
        } else {
            f (root -> left, s, ans);
            f (root -> right, s, ans);
        }
            
        s = t;
    } 
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        f(root, "", ans);
        return ans;
    }
};