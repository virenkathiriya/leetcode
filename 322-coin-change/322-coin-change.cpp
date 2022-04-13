class Solution {
public:
    int coinChange(vector<int>& c, int A) {
        if (A == 0) return 0;
        
        sort(c.begin(), c.end());
        int n = c.size();
        vector<vector<int>> dp(n, vector<int> (A + 1, INT_MAX));
        if (c[0] > A) return -1;
        for (int i = c[0]; i <= A; i += c[0])
            dp[0][i] = i / c[0];
        for (int i = 0; i < n; i++) dp[i][0] = 0;
    
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= A; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= c[i] && dp[i][j - c[i]] != INT_MAX)
                    dp[i][j] = min(dp[i][j - c[i]] + 1, dp[i][j]);
            }
        }
        return dp[n - 1][A] == INT_MAX ? -1: dp[n - 1][A];
    }
};