class Solution {
public:
    int minimumXORSum(vector<int>& a, vector<int>& b) {
        int n = b.size();
        vector<vector<int>> dp(2, vector<int>(1 << n, INT_MAX));
        for (int i = 0; i < n; i++) dp[0][1 << i] = a[0] ^ b[i];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < (1 << n); j++) {
                if (__builtin_popcount(j) == i) {
                    for (int m = 0; m < n; m++) {
                        if (!(j & (1 << m))) {
                            dp[i % 2][j + (1 << m)] = min(dp[i % 2][j + (1 << m)], dp[(i + 1) % 2][j] + (a[i] ^ b[m]));
                        }
                    }
                }
            }
        }
        return dp[(n - 1) % 2][(1 << n) - 1];
    }
};