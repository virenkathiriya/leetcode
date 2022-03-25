class Solution {
public:
    int maxDistance(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        int mx = m + n;
        queue<pair<int, int>> q;
        vector<vector<int>> dp(n, vector<int> (m, mx));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 1) {
                    q.push({i, j});
                    dp[i][j] = 0;
                }
            }
        }
        
        vector<vector<int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        if (q.empty() || q.size() == n * m) return -1;
        int ans = 0;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.first, y = it.second;
            for (int i = 0; i < 4; i++) {
                int xN = d[i][0] + x, yN = d[i][1] + y;
                if (xN < 0 || xN >= n || yN < 0 || yN >= m) continue;
                if (dp[xN][yN] > dp[x][y] + 1) {
                    ans = max(ans, dp[xN][yN] = dp[x][y] + 1);
                    q.push({xN, yN});
                }
            }
        }
        
        return ans;
    }
};