class Solution {
public:
    int maxProfit(vector<int>& v, int f) {
        int N = v.size();
        vector<vector<int>> dp(2, vector<int> (2, 0));
        for (int i = N - 1; i >= 0; --i) {
            for (int j = 0; j < 2; j++) {
                int t = i % 2;
                if (j == 0) dp[t][j] = max(dp[t ^ 1][j], -v[i] + dp[t ^ 1][1]);
                else dp[t][j] = max(dp[t ^ 1][j], v[i] + dp[t ^ 1][0] - f);
            }
        }
        return dp[0][0];
    }
};