class Solution {
public:
    bool isInterleave(string a, string b, string c) {
        int aN = a.size(), bN = b.size(), cN = c.size();
        if (aN == 0 && bN == 0 && cN == 0) return true;
        if (aN + bN != cN) return false;
        vector<bool> dp(bN + 1, 0);
        
        for (int i = 0; i <= aN; i++) {
            for (int j = 0; j <= bN; j++) {
                if (i == 0 && j == 0) dp[j] = true;
                else if (i == 0)
                    dp[j] = dp[j - 1] && b[j - 1] == c[i + j - 1];
                else if (j == 0)
                    dp[j] = dp[j] && a[i - 1] == c[i + j - 1];
                else {
                    dp[j] = (dp[j] && a[i - 1] == c[i + j - 1]) || (dp[j - 1] && b[j - 1] == c[i + j - 1]);
                }
            }
        }
        return dp[bN];
    }
};