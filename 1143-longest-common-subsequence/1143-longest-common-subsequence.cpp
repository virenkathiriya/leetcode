class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(2, vector<int> (m, 0));
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                dp[i % 2][j] = max({(j > 0) ? dp[i % 2][j - 1] : 0, dp[(i + 1) % 2][j] , (a[i] == b[j]) +  (j > 0 ? dp[(i + 1) % 2][j - 1]: 0)});
        return dp[(n + 1) % 2][m - 1];
    }
};