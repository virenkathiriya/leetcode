class Solution {
public:
    int numSquares(int n) {
        int m = sqrt(n) + 1;
        vector<int> dp(n + 1, INT_MAX);
        
        dp[0] = 0;
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < n + 1; j++) {
                if (j - (i * i) >= 0)
                dp[j] = min(dp[j], dp[j - (i * i)] + 1);
            }
        }
        
        return dp[n];
    }
};