class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        int mx = n + m;
        vector<vector<int>> dp(n, vector<int> (m, mx));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 0) dp[i][j] = 0;
                else {
                    int up = mx, left = mx;
                    if (i - 1 >= 0) up = dp[i - 1][j];
                    if (j - 1 >= 0) left = dp[i][j - 1];
                    dp[i][j] = min(up, left) + 1;
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int right = mx, down = mx;
                if (i + 1 < n) down = dp[i + 1][j];
                if (j + 1 < m) right = dp[i][j + 1];
                dp[i][j] = min(min(down, right) + 1, dp[i][j]);
            }
        }
        return dp;
    }
};