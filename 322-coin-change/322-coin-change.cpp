class Solution {
public:
    int coinChange(vector<int>& c, int A) {
        if (A == 0) return 0;
        
        sort(c.begin(), c.end());
        int n = c.size();
        vector<vector<int>> dp(2, vector<int> (A + 1, INT_MAX));
        if (c[0] > A) return -1;
        for (int i = c[0]; i <= A; i += c[0])
            dp[0][i] = i / c[0];
        for (int i = 0; i < 2; i++) dp[i][0] = 0;
    
        for (int i = 1; i < n; i++) {
            int t = i % 2;
            for (int j = 1; j <= A; j++) {
                dp[t][j] = dp[!t][j];
                if (j >= c[i] && dp[t][j - c[i]] != INT_MAX)
                    dp[t][j] = min(dp[t][j - c[i]] + 1, dp[t][j]);
            }
        }
        return dp[(n + 1) % 2][A] == INT_MAX ? -1: dp[(n + 1) % 2][A];
    }
};