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
    vector<int> ans;
    void dfs(Node* u) {
        if(!u) return;
        ans.push_back(u -> val);
        for (Node *v: u -> children) dfs(v);
    }
    vector<int> preorder(Node* root) {
        dfs(root);
        return ans;
    }
};