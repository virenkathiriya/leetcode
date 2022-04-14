class Solution {
public:
    int maximalSquare(vector<vector<char>>& g) {
        int n = g.size(), m = g[0].size();
        vector<int> dp(m, 0);
        int ans = 0, upleft = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int _ = dp[j];
                if (g[i][j] == '1') {
                    dp[j] = min({(j > 0 ? dp[j - 1]: 0), dp[j], upleft}) + 1;
                    ans = max(ans, dp[j]);
                } else dp[j] = 0;
                upleft = _;
            }
        }
        return ans * ans;
    }
};