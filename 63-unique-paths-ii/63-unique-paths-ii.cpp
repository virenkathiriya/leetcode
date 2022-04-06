class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<int> dp(m, 0);
        if (g[0][0] == 1) return 0;
        else dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j]) {dp[j] = 0; continue;}
                if (i == 0 && j == 0) continue;
                if (i == 0 || g[i - 1][j]) dp[j] = 0;
                if (j > 0 && !g[i][j - 1]) dp[j] += dp[j - 1];
            }
        }
        return dp[m - 1];
    }
};