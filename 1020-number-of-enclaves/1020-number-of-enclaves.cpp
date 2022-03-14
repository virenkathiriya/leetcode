class Solution {
public:
    void dfs(vector<vector<int>>& g, int x, int y) {
        if(g[x][y] == 0 || g[x][y] == -1) return;
        g[x][y] = 0;
        int n = g.size();
        int m = g[0].size();
        
        if(x + 1 < n) dfs(g, x + 1, y);
        if(x - 1 >= 0) dfs(g, x - 1, y);
        if(y + 1 < m) dfs(g, x, y + 1);
        if(y - 1 >= 0) dfs(g, x, y - 1);
    }
    int numEnclaves(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        for(int i = 0; i < n; i++) {
            if(g[i][0] == 1) dfs(g, i, 0);
            if(g[i][m - 1] == 1) dfs(g, i, m - 1);
        }
        for(int i = 0; i < m; i++) {
            if(g[0][i] == 1) dfs(g, 0, i);
            if(g[n - 1][i] == 1) dfs(g, n - 1, i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) ans += g[i][j];
        return ans;
    }
};