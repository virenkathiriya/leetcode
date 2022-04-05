class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 1);
        vector<int> l(3, 0);
        for (int i = 1; i < n; i++) {
            dp[i] = min({
                dp[l[0]] * 2,
                dp[l[1]] * 3,
                dp[l[2]] * 5
            });
            
            if (dp[i] == dp[l[0]] * 2) l[0]++;
            if (dp[i] == dp[l[1]] * 3) l[1]++;
            if (dp[i] == dp[l[2]] * 5) l[2]++;
        }
        return dp[n - 1];
    }
};