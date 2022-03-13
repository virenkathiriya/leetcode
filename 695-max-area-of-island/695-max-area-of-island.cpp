class Solution {
public:
    void dfs(vector<vector<int>>& g, int x, int y, int &cnt) {
        if(g[x][y] == 0 || g[x][y] == -1) return;
        g[x][y] = -1;
        int n = g.size();
        int m = g[0].size();
        cnt++;
        if(x + 1 < n) dfs(g, x + 1, y, cnt);
        if(x - 1 >= 0) dfs(g, x - 1, y, cnt);
        
        if(y + 1 < m) dfs(g, x, y + 1, cnt);
        if(y - 1 >= 0) dfs(g, x, y - 1, cnt);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(g[i][j] == 1) {
                    int cnt = 0;
                    dfs(g, i, j, cnt);
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};