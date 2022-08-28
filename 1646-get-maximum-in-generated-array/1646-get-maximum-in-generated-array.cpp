class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        if (n == 0) return dp[0];
        dp[1] = 1;
        for (int i = 1; i * 2 + 1 <= n; ++i) {
            dp[i * 2] = dp[i];
            dp[i * 2 + 1] = dp[i] + dp[i + 1];
        }
        return *max_element(dp.begin(), dp.end());
    }
};