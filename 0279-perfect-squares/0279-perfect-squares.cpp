class Solution {
public:
    int numSquares(int n) {
        int m = sqrt(n) + 1;
        vector<int> v(m + 1, 0);
        for (int i = 0; i <= m; ++i) v[i] = i * i;
        
        vector<int> dp(n + 1, INT_MAX);
        
        dp[0] = 0;
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < n + 1; j++) {
                if (j - v[i] >= 0)
                dp[j] = min(dp[j], dp[j - v[i]] + 1);
            }
        }
        
        return dp[n];
    }
};