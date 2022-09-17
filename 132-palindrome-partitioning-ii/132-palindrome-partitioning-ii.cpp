class Solution {
public:
    bool ip(string &s, int i, int j) {
        while (i < j) if (s[i++] != s[j--]) return false;
        return true;
    }
    
    int minCut(string s) {
        int N = s.size();
        vector<int> dp(N + 1, 0);
        for (int i = N - 1; i >= 0; --i) {
            int ans = INT_MAX;
            for (int j = i; j < N; j++) if (ip(s, i, j)) ans = min(ans, 1 + dp[j + 1]);
            dp[i] = ans;
        }
        return dp[0] - 1;
    }
};