class Solution {
public:
    bool ip(string &s, int i, int j) {
        while (i < j) if (s[i++] != s[j--]) return false;
        return true;
    }
    
    int f(string &s, int i, int n, vector<int> &dp) {
        if (i == n) return 0;
        if (dp[i]) return dp[i];
        int ans = INT_MAX;
        for (int j = i; j < n; j++) if (ip(s, i, j)) ans = min(ans, 1 + f(s, j + 1, n, dp));
        return dp[i] = ans;
    }
    
    int minCut(string s) {
        vector<int> dp(s.size(), 0);
        f(s, 0, s.size(), dp);
        return dp[0] - 1;
    }
};