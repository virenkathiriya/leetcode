/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        int level = 0;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int cnt = 0;
            Node* pre = NULL;
            while (cnt < (1 << level)) {
                Node* cur = q.front();
                q.pop();
                if (cur -> left) q.push(cur -> left);
                if (cur -> right) q.push(cur -> right);
                
                if (cnt != 0) {
                    pre -> next = cur;
                }
                pre = cur;
                cnt++;
            }
            level++;
        }
        return root;
    }
};