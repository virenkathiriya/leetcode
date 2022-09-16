class Solution {
public:
    int maximumScore(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(2, vector<int> (m + 1, 0));
        for (int o = m - 1; o >= 0; o--) {
            int oo = o % 2;
            for (int l = o; l >= 0; l--) dp[oo][l] = max(dp[oo ^ 1][l + 1] + a[l] * b[o], dp[oo ^ 1][l] + a[n - 1 - (o - l)] * b[o]);
        }
        return dp[0][0];
    }
};