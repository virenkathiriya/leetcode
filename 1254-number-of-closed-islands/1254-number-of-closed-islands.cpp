class Solution {
public:
    void dfs(vector<vector<int>>& g, int x, int y) {
        if(g[x][y] == 1 || g[x][y] == -1) return;
        
        g[x][y] = -1;
        
        int n = g.size();
        int m = g[0].size();
        
        if(x + 1 < n) dfs(g, x + 1, y);
        if(x - 1 >= 0) dfs(g, x - 1, y);
        
        if(y + 1 < m) dfs(g, x, y + 1);
        if(y - 1 >= 0) dfs(g, x, y - 1);
        
    }
    
    int closedIsland(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(g[i][0] == 0) dfs(g, i, 0);
            if(g[i][m - 1] == 0) dfs(g, i, m - 1);
        }
        for(int i = 0; i < m; i++) {
            if(g[0][i] == 0) dfs(g, 0, i);
            if(g[n - 1][i] == 0) dfs(g, n - 1, i);
        }
        for(int i = 1; i < n - 1; i++) {
            for(int j = 1; j < m - 1; j++) {
                if(g[i][j] == 0) {
                    dfs(g, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};