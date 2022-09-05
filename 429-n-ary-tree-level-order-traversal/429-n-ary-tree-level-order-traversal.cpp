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
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()) {
            int m = q.size();
            vector<int> tmp;
            for (int i = 0; i < m; i++) {
                Node* u = q.front();
                q.pop();
                tmp.emplace_back(u -> val);
                for (Node* v: u -> children) {
                    if (v) {
                        q.push(v);
                    }
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};