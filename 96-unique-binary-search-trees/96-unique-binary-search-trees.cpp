class Solution {
public:
    vector<int> dp;
    int solve(int n) {
        if (dp[n] != 0) return dp[n];
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += solve(i - 1) * solve(n - i);
        }
        dp[n] = ans;
        return dp[n];
    }
    int numTrees(int n) {
        dp.resize(n + 1, 0);
        dp[0] = dp[1] = 1;
        return solve(n);
    }
};