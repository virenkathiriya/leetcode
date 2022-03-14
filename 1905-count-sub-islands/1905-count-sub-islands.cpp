class Solution {
public:
    bool dfs(vector<vector<int>>& g, vector<vector<int>>& s, int x, int y) {
        if(g[x][y] == 0) return true;
        if(g[x][y] != s[x][y]) return false;
        g[x][y] = 0;
        int n = g.size();
        int m = g[0].size();
        
        bool ok = true;
        if(x + 1 < n) ok &= dfs(g, s, x + 1, y);
        if(x - 1 >= 0) ok &= dfs(g, s, x - 1, y);
        if(y + 1 < m) ok &= dfs(g, s, x, y + 1);
        if(y - 1 >= 0) ok &= dfs(g, s, x, y - 1);
        return ok;
    }
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
        int n = g1.size();
        int m = g1[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(g2[i][j] == 1) {
                    ans += dfs(g2, g1, i, j);;
                }
            }
        }
        return ans;
    }
};