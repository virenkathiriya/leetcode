class Solution {
public:
    int minimumXORSum(vector<int>& a, vector<int>& b) {
        int n = b.size();
        vector<int> p(n + 1, 1);
        for (int i = 1; i <= n; i++) p[i] = 1 << i;
        vector<vector<int>> dp(2, vector<int>(p[n], INT_MAX));
        for (int i = 0; i < n; i++) dp[0][p[i]] = a[0] ^ b[i];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < p[n]; j++) {
                if (__builtin_popcount(j) == i) {
                    for (int m = 0; m < n; m++) {
                        if (!(j & p[m])) {
                            dp[i % 2][j + p[m]] = min(dp[i % 2][j + p[m]], dp[(i + 1) % 2][j] + (a[i] ^ b[m]));
                        }
                    }
                }
            }
        }
        return dp[(n - 1) % 2][p[n] - 1];
    }
};