class Solution {
public:
    int numSquares(int n) {
        int m = sqrt(n) + 1;
        vector<int> v(m + 1, 0);
        for (int i = 0; i <= m; ++i) v[i] = i * i;
        vector<vector<int>> dp(101, vector<int>(n + 1, INT_MAX));
        
        for (int i = 0; i <= m; i++) dp[i][0] = 0;
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < n + 1; j++) {
                if (j - v[i] < 0 || dp[i][j - v[i]] == INT_MAX) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - v[i]] + 1);
                }
            }
        }
        
        return dp[m][n];
    }
};