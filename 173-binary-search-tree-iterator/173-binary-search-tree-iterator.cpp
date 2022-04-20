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
class BSTIterator {
public:
    TreeNode* cur;
    BSTIterator(TreeNode* root) {
        cur = root;
    }
    
    int next() {
        int ans;
        while (cur) {
            if (!cur -> left) {
                ans = cur -> val;
                cur = cur -> right;
                break;
            } else {
                TreeNode *temp = cur -> left;
                while (temp -> right && temp -> right != cur) temp = temp -> right;
                if (temp -> right) {
                    ans = cur -> val;
                    temp -> right = NULL;
                    cur = cur -> right;
                    break;
                } else {
                    temp -> right = cur;
                    cur = cur -> left;
                }
            }
        }
        return ans;
    }
    
    bool hasNext() {
        return cur != NULL;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */