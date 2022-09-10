class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (3, 0)));
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy < 2; buy++) {
                for (int t = 1; t <= 2; t++) {
                    if (buy == 0) {
                        dp[i][buy][t] = max
                        (
                            0 + dp[i + 1][buy][t],
                            -v[i] + dp[i + 1][1][t]
                        );
                    } else {
                        dp[i][buy][t] = max
                        (
                            0 + dp[i + 1][buy][t],
                            v[i] + dp[i + 1][0][t - 1]
                        );
                    }
                }
            }
        }
        return dp[0][0][2];
    }
};