class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& g) {
        int n = g.size();
        vector<vector<int>> dp(2, vector<int> (n, INT_MAX));
        dp[0] = g[0];
        for (int i = 1; i < n; i++) {
            int t = i % 2;
            for (int j = 0; j < n; j++) {
                dp[t][j] = min({dp[!t][j], (j > 0 ? dp[!t][j - 1]: INT_MAX), (j + 1 < n ? dp[!t][j + 1]: INT_MAX)});
                dp[t][j] += g[i][j];
            }
        }
        int _ = (n + 1) % 2;
        return *min_element(dp[_].begin(), dp[_].end());
    }
};