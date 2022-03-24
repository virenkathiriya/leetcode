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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;
        
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({root1, root2});
        while (!st.empty()) {
            auto it = st.top();
            st.pop();
            // first will always have value or null(in case both are null);
            if (it.first == NULL || it.second == NULL) continue; 
            
            it.first -> val += it.second -> val;
            if (!it.first -> left) {
                it.first -> left = it.second -> left;
            } else {
                st.push({it.first -> left, it.second -> left});
            }
            
            if (!it.first -> right) {
                it.first -> right = it.second -> right;
            } else {
                st.push({it.first -> right, it.second -> right});
            }
        }
        return root1;
    }
};