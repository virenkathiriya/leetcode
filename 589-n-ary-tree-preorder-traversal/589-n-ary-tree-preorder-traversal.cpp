/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void f(Node* u, vector<int> &x) {
        if (!u) return;
        x.push_back(u -> val);
        for (Node* v: u -> children) {
            f(v, x);
        }
    }
    vector<int> preorder(Node* root, vector<int> x = {}) {
        f(root, x);
        return x;
    }
};