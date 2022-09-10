class Solution {
public:
    int maxProfit(vector<int>& v) {
        int N = v.size();
        vector<vector<int>> dp(3, vector<int> (2, 0));
        for (int i = N - 1; i >= 0; i--) {
            int i0 = i % 3;
            int i1 = (i + 1) % 3;
            int i2 = (i + 2) % 3;
            for (int b = 0; b <= 1; b++) {
                if (b == 0) {
                    dp[i0][b] = max(0 + dp[i1][0], -v[i] + dp[i1][1]);
                } else {
                    dp[i0][b] = max(0 + dp[i1][1], v[i] + dp[i2][0]);
                }
            }
        }
        return dp[0][0];
    }
};