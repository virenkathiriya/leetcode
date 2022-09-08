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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* cur = root;
        vector<int> ans;
        while (cur) {
            if (!cur -> left) {
                ans.push_back(cur -> val);
                cur = cur -> right;
            } else {
                TreeNode* ptr = cur -> left;
                // go to far right and put a thread to this.
                while (ptr -> right && ptr -> right != cur) {
                    ptr = ptr -> right;
                }
                if (!ptr -> right) {
                    ptr -> right = cur;
                    cur = cur -> left;
                } else {
                    ptr -> right = NULL;
                    ans.push_back(cur -> val);
                    cur = cur -> right;
                }
            }
        }
        return ans;
    }
};