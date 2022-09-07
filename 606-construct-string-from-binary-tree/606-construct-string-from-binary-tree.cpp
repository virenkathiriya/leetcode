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
    string dfs(TreeNode* root) {
        if(!root) return "";
        string s;
        s += "(";
        s += to_string(root -> val);
        string l = dfs(root -> left);
        string r = dfs(root -> right);
        
        if (l == "" && r != "") s += "()" + r;
        else s += l + r;
        
        s += ")";
        return s;
    }
    
    string tree2str(TreeNode* root) {
        if (!root) return "";
        string s = to_string(root -> val);
        string l = dfs(root -> left);
        string r = dfs(root -> right);
        if (l == "" && r != "") s += "()" + r;
        else s += l + r;
        return s;
    }
};