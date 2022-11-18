class Solution {
public:
    void dfs(int u, int p, vector<vector<int>>& adj, vector<bool> &vis) {
        for (int &v: adj[u]) {
            if (!vis[v] && v != p) {
                vis[v] = true;
                dfs(v, u, adj, vis);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& adj) {
        int N = adj.size();
        vector<bool> vis(N, false);
        vis[0] = true;
        dfs(0, -1, adj, vis);
        return accumulate(vis.begin(), vis.end(), 0) == N;
    }
};