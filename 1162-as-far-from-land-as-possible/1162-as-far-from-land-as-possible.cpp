class Solution {
public:
    int maxDistance(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        int mx = m + n;
        vector<vector<int>> dp(n, vector<int> (m, mx));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 1) {
                    dp[i][j] = 0;
                }
                if (i - 1 >= 0 && dp[i - 1][j] != mx) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                }
                if (j - 1 >= 0 && dp[i][j - 1] != mx) {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
            }
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i + 1 < n && dp[i + 1][j] != mx) {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                }
                if (j + 1 < m && dp[i][j + 1] != mx) {
                    dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ((ans == 0 || ans == m + n) ? -1 : ans);
    }
};