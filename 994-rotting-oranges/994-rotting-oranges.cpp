class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX - 1));
        queue<vector<int>> q;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (g[i][j] == 2) {
            dist[i][j] = 0;
            q.push({i, j});
        }
        
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (int i = 0; i < dir.size(); i++) {
                int x = cur[0], y = cur[1];
                int xN = x + dir[i][0], yN = y + dir[i][1];
                if (xN < 0|| xN >= n || yN < 0 || yN >= m) continue;
                if (g[xN][yN] == 1 && dist[xN][yN] > dist[x][y] + 1) {
                    dist[xN][yN] = dist[x][y] + 1;
                    q.push({xN, yN});
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0;j < m; j++) {
                if (g[i][j] == 1 && dist[i][j] == INT_MAX - 1) {
                    return -1;
                } else if (g[i][j] == 1){
                    ans = max(ans, dist[i][j]);
                }
            }
        }
        return ans;
    }
};