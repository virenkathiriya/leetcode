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
        
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        pair<Node*, int>  prev = {NULL, -1};
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            if (prev.second != p.second) {
                prev = p;
            } else {
                prev.first -> next = p.first;
                prev = p;
            }
            if (p.first -> left) q.push({p.first -> left, p.second + 1});
            if (p.first -> right) q.push({p.first -> right, p.second + 1});
        }
        return root;
    }
};