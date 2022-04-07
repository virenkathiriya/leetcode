class Solution {
public:
    int sum(vector<long long> c) {
        long long ans = 0;
        int MOD = 1000000007;
        for (auto &x: c) {
            ans = (ans + x) % MOD;
        }
        return ans;
    }
    int countVowelPermutation(int n) {
        n++;
        vector<vector<long long>> dp(n, vector<long long> (5, 0));
        for (int i = 0; i < 5; i++) dp[1][i] = 1;
        
        for (int i = 2; i < n; i++) {
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = sum ({dp[i - 1][0], dp[i - 1][2]});
            dp[i][2] = sum ({dp[i - 1][0], dp[i - 1][1], dp[i - 1][3], dp[i - 1][4]});
            dp[i][3] = sum ({dp[i - 1][2], dp[i - 1][4]});
            dp[i][4] = dp[i - 1][0];
        }
        return sum(dp[n - 1]);
    }
};