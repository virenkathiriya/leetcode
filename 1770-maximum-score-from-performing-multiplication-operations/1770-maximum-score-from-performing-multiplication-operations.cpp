class Solution {
public:
    int maximumScore(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(m + 1, vector<int> (m + 1, 0));
        for (int o = m - 1; o >= 0; o--) {
            for (int l = o; l >= 0; l--) {
                dp[o][l] = max(dp[o + 1][l + 1] + a[l] * b[o], dp[o + 1][l] + a[n - 1 - (o - l)] * b[o]);
            }
        }
        return dp[0][0];
    }
};