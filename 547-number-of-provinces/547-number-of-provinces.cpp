class Solution {
public:
    void dfs(vector<vector<int>>& adjm, vector<bool> &vis, int u, int &n) {
        if (vis[u]) return;
        vis[u] = true;
        for (int j = 0; j < n; j++) if (adjm[u][j] && !vis[j]) dfs(adjm, vis, j, n);
    }
    int findCircleNum(vector<vector<int>>& adjm) {
        int n = adjm.size();
        vector<bool> vis(n, false);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(adjm, vis, i, n);
                cnt++;
            }
        }
        return cnt;
    }
};