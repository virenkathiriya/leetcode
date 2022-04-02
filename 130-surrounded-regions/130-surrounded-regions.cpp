class Solution {
public:
    void dfs(vector<vector<char>>& g, int x, int y,const int n, const int m) {
        if (g[x][y] == 'X' || g[x][y] == 'R') return;
        g[x][y] = 'R';
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i = 0; i < 4; i++) {
            int X = x + dir[i][0], Y = y + dir[i][1];
            if (X < 0 || X > n - 1 || Y < 0 || Y > m - 1) continue;
            if (g[X][Y] == 'O') {
                dfs(g, X, Y, n, m);
            }
        }
    }
    void solve(vector<vector<char>>& g) {
        int n = g.size(), m = g[0].size();
        for (int i = 0; i < m; i++) {
            if (g[0][i] == 'O')
                dfs(g, 0, i, n, m);
            if (g[n - 1][i] == 'O')
                dfs(g, n - 1, i, n, m);
        }
        for (int i = 0; i < n; i++) {
            if (g[i][0] == 'O')
                dfs(g, i, 0, n, m);
            if (g[i][m - 1] == 'O')
                dfs(g, i, m - 1, n, m);
        }
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {if (g[i][j] == 'O') g[i][j] = 'X'; if (g[i][j] == 'R') g[i][j] = 'O';}
    }
};