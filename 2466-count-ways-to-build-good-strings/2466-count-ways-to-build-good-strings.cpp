class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> dp(2 * high, 0);
        long long M = 1000000007;
        dp[0] = 1;
        for (int i = 0; i <= high; i++) {
            if (i + zero <= high)
            dp[i + zero] = (dp[i + zero] + dp[i]) % M; 
            if (i + one <= high)
            dp[i + one] = (dp[i + one] + dp[i]) % M;
        }
        long long sum = 0;
        for (int i = low; i <= high; i++) {
            sum = (sum + dp[i]) % M;
        }
        return sum;
    }
};