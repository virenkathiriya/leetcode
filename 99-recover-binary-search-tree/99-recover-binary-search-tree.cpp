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
    void recoverTree(TreeNode *root) {
        
        TreeNode *cur = root;
        TreeNode *f, *s;
        f = s = NULL;
        
        TreeNode *pre = NULL;
        while (cur) {
            if (!cur -> left) {
                if (pre && (pre -> val > cur -> val)) {
                        if (!f)  {
                            f = pre, s = cur;
                        } else {
                            s = cur;
                        }
                    }
                pre = cur;
                cur = cur -> right;
            } else {
                TreeNode *temp = cur -> left;
                while (temp -> right && temp -> right != cur) temp = temp -> right;
                
                if (temp -> right) {
                    if (pre && (pre -> val > cur -> val)) {
                        if (!f)  {
                            f = pre, s = cur;
                        } else {
                            s = cur;
                        }
                    }
                    temp -> right = NULL;
                    
                    pre = cur;
                    cur = cur -> right;
                } else {
                    temp -> right = cur;
                    cur = cur -> left;
                }
            }
        }
        if (f && s) swap(f -> val, s -> val);
    }
};