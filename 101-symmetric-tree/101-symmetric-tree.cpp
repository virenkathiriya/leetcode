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
    bool ok = true;
    void f(TreeNode* r1, TreeNode* r2) {
        if (!ok) return;
        if (r1 && r2) { 
            ok &= (r1 -> val == r2 -> val);
            f(r1 -> left, r2 -> right);
            f(r1 -> right, r2 -> left);
        } else {
            ok &= !(r1 || r2);
        }
        
    }
    bool isSymmetric(TreeNode* root) {
        f(root -> left, root -> right);
        return ok;
    }
};