class Solution {
public:
    bool bobdfs(int u, int p, int t, vector<int> &bobt, int bob, vector<vector<int>>& adj) {
        if (u == 0) return true;
        bool isbobpath = false;
        for (int &v: adj[u]) {
            if (v != p) {
                bool ok = bobdfs(v, u, t + 1, bobt, bob, adj);
                if (ok) {
                    bobt[v] = t + 1;
                    isbobpath = true;
                }
            }
        }
        return isbobpath;
    }
    
    int ans = INT_MIN;
    
    void dfs(vector<vector<int>>& adj, vector<int> &bobt, int u, int p, int curt, int curans, vector<int>& amount) {
        for (int &v: adj[u]) {
            if (v != p) {
                int add = 0;
                if ((curt + 1) == bobt[v]) add = amount[v] / 2;
                else if (curt + 1 < bobt[v]) add = amount[v];
                dfs(adj, bobt, v, u, curt + 1, curans + add, amount);
            }
        }
        if (adj[u].size() == 1 && u != 0) {
            ans = max(ans, curans);
        }
    }
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int N = edges.size() + 1;
        vector<vector<int>> adj(N);
        for (vector<int> &v: edges) {
            int x = v[0], y = v[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        vector<int> bobt(N, INT_MAX);
        bobt[bob] = 0;
        bobdfs(bob, -1, 0, bobt, bob, adj);
        
        dfs(adj, bobt, 0, -1, 0, amount[0], amount);
        return ans;
    }
};