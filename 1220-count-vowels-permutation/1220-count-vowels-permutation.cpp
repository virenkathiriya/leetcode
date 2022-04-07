class Solution {
public:
    int countVowelPermutation(int n) {
        n++;
        vector<vector<long long>> dp(2, vector<long long> (5, 0));
        for (int i = 0; i < 5; i++) dp[0][i] = 1;
        int MOD = 1000000007;
        
        for (int i = 2; i < n; i++) {
            dp[1][0] = dp[0][1];
            dp[1][1] = (dp[0][0] + dp[0][2]) % MOD ;
            dp[1][2] = (dp[0][0] + dp[0][1] + dp[0][3] + dp[0][4]) % MOD;
            dp[1][3] = (dp[0][2] + dp[0][4]) % MOD;
            dp[1][4] = dp[0][0];
            for (int j = 0; j < 5; j++) swap(dp[1][j], dp[0][j]);
        }
        return (dp[0][0] + dp[0][1] + dp[0][2] + dp[0][3] + dp[0][4]) % MOD;
    }
};