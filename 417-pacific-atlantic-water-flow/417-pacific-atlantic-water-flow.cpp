class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n = h.size(), m = h[0].size();
        vector<vector<int>> g(n, vector<int> (m, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {q.push({i, 0}); g[i][0] = 0;}
        for (int j = 1; j < m; j++) {q.push({0, j}); g[0][j] = 0;}
        vector<vector<int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int xN = it.first + d[i][0], yN = it.second + d[i][1];
                if (xN < 0 || xN >= n || yN < 0 || yN >= m) continue;
                if (h[xN][yN] >= h[it.first][it.second] && g[xN][yN] == -1) {
                    g[xN][yN] = 0;
                    q.push({xN, yN});
                }
            }
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            q.push({i, m - 1}); 
            if (g[i][m - 1] == 0) {
                ans.push_back({i, m - 1});
            }
            g[i][m - 1] = 1;
        }
        for (int j = 0; j < m - 1; j++) {
            q.push({n - 1, j});
            if (g[n - 1][j] == 0) {
                ans.push_back({n - 1, j});
            } 
            g[n - 1][j] = 1;
        }
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int xN = it.first + d[i][0], yN = it.second + d[i][1];
                if (xN < 0 || xN >= n || yN < 0 || yN >= m) continue;
                if (h[xN][yN] >= h[it.first][it.second] && (g[xN][yN] == -1 || g[xN][yN] == 0)) {
                    if (g[xN][yN] == 0) {
                        ans.push_back({xN, yN}); 
                    } 
                    g[xN][yN] = 1;
                    q.push({xN, yN});
                }
            }
        }
        return ans;
    }
};