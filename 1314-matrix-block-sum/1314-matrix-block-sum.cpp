class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& g, int k) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> dp(n, vector<int> (m, 0));
        dp[0][0] = g[0][0];
        for (int i = 1; i < n; i++) dp[i][0] = dp[i - 1][0] + g[i][0];
        for (int i = 1; i < m; i++) dp[0][i] = dp[0][i - 1] + g[0][i];
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + g[i][j];
            }
        } 
        pair<int, int> tr, bl, tl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tr = {max(i - k - 1, -1), min(m - 1, j + k)}; 
                bl = {min(n - 1, i + k), max(-1, j - k - 1)}; 
                tl = {max(i - k - 1, -1), max(j - k - 1, -1)};
                g[i][j] = dp[min(n - 1, i + k)][min(m - 1,  j + k)];
                if (tr.first >= 0 && tr.second < m) g[i][j] -= dp[tr.first][tr.second];
                if (bl.second >= 0 && bl.first < n) g[i][j] -= dp[bl.first][bl.second];
                if (tl.first >= 0 && tl.second >= 0) g[i][j] += dp[tl.first][tl.second];
            }
        }
        return g;
    }
};