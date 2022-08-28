class Solution {
public:
    bool mahn(vector<vector<int>>& a, int k, vector<int> &ans) {
        vector<int> adj[k];
        vector<int> indegree(k, 0);
        for (vector<int> &x: a) {
            int from = x[0];
            int to = x[1];
            from--, to--;
            adj[from].push_back(to);
            indegree[to]++;
        }
        
        queue<int> q;
        for (int i = 0; i < k; i++) if (indegree[i] == 0) q.push(i);
        
        int index = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            ans[u] = index++;
            for (int &v: adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) q.push(v);
            }
        }
        return index == k;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<int> rT(k), cT(k);
        if (!mahn(a, k, rT) or !mahn(b, k, cT)) return {};
        vector<vector<int>> ans(k, vector<int> (k, 0));
        for (int i = 0; i < k; i++) ans[rT[i]][cT[i]] = i + 1;
        return ans;
    }
};