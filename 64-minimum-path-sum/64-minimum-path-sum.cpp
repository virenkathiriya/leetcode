class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> dp(2, vector<int> (m, 0));
        dp[0][0] = g[0][0];
        for (int i = 1; i < m; i++) dp[0][i] = dp[0][i - 1] + g[0][i];
        for (int i = 1; i < n; i++) {
            int t = i % 2;
            for (int j = 0; j < m; j++) dp[t][j] = min(j > 0 ? dp[t][j - 1]: INT_MAX, dp[!t][j]) + g[i][j];
        }
        return dp[(n + 1) % 2][m - 1];
    }
};