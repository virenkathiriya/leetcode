class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = ((i + 1 < n && j > 0 && (i + 1 <= j - 1)) ? dp[i + 1][j - 1] : 0) + ((i == j) ? 1 : 2);
                } else {
                    dp[i][j] = max((i + 1 < n) ? dp[i + 1][j] : 0, (j > 0) ? dp[i][j - 1] : 0);
                }
            }
        }
        return dp[0][n - 1];
    }
};