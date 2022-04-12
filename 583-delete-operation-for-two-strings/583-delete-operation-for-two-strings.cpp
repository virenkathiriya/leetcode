class Solution {
public:
    int minDistance(string a, string b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(2, vector<int> (m, 0));
        for (int i = 0; i < n; i++) {
            int c = i % 2;
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j]) {
                    dp[c][j] = 1 + (j > 0 ? dp[!c][j - 1]: 0);
                } else {
                    dp[c][j] = max(dp[!c][j], j > 0 ? dp[c][j - 1]: 0);
                }
            }
        }
        return n + m - (2 * dp[(n + 1) % 2][m - 1]);
    }
};