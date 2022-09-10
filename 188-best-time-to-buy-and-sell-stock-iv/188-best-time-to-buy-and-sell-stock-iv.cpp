class Solution {
public:
    int maxProfit(int k, vector<int>& v) {
        int n = v.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>> (2, vector<int> (k + 1, 0)));
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy < 2; buy++) {
                for (int t = 1; t <= k; t++) {
                    int ii = i % 2;
                    if (buy == 0) {
                        dp[ii][buy][t] = max
                        (
                            0 + dp[ii ^ 1][buy][t],
                            -v[i] + dp[ii ^ 1][1][t]
                        );
                    } else {
                        dp[ii][buy][t] = max
                        (
                            0 + dp[ii ^ 1][buy][t],
                            v[i] + dp[ii ^ 1][0][t - 1]
                        );
                    }
                }
            }
        }
        return max(dp[0][0][k], dp[1][0][k]);
    }
};