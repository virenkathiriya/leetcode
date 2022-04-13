class Solution {
public:
    int coinChange(vector<int>& c, int A) {
        if (A == 0) return 0;
        
        sort(c.begin(), c.end());
        int n = c.size();
        vector<int> dp(A + 1, INT_MAX);
        if (c[0] > A) return -1;
        for (int i = c[0]; i <= A; i += c[0])
            dp[i] = i / c[0];
        dp[0] = 0;
    
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= A; j++) {
                if (j >= c[i] && dp[j - c[i]] != INT_MAX)
                    dp[j] = min(dp[j - c[i]] + 1, dp[j]);
            }
        }
        return dp[A] == INT_MAX ? -1: dp[A];
    }
};