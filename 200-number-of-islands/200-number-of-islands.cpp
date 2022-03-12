class Solution {
public:
    void dfs(vector<vector<char>>& g, int x, int y) {
        if(g[x][y] != '1') return;
        int n = g.size(), m = g[0].size();        
        g[x][y] = '0';
        if(x - 1 >= 0) dfs(g, x - 1, y);
        if(x + 1 < n) dfs(g, x + 1, y);
        if(y - 1 >= 0) dfs(g, x, y - 1);
        if(y + 1 < m) dfs(g, x, y + 1);
    }
    int numIslands(vector<vector<char>>& g) {
        int n = g.size(), m = g[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(g[i][j] == '1') {
                    dfs(g, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};