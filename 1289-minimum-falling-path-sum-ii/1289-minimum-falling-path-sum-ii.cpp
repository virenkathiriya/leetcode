class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& g) {
        int n = g.size();
        vector<vector<int>> dp(2, vector<int> (n, INT_MAX));
        dp[0] = g[0];
        for (int i = 1; i < n; i++) {
            int t = i % 2;
            for (int j = 0; j < n; j++) {
                dp[t][j] = INT_MAX;
                for (int  k = 0; k < n; k++) {
                    if (k != j) 
                        dp[t][j] = min(dp[t][j], dp[!t][k]);
                }
                dp[t][j] += g[i][j];
            }
        }
        int _ = (n + 1) % 2;
        return *min_element(dp[_].begin(), dp[_].end());
    }
};