class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& v, int k) {
        int n = v.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int ans = 0, maxTillNow = INT_MIN;
            for (int j = i; j < min(i + k, n); ++j) {
                maxTillNow = max(maxTillNow, v[j]);
                ans = max(ans, maxTillNow * (j - i + 1) + dp[j + 1]);
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};
// f(i) = 
//     for j = i; j = i + k - 1; j++ 
//         maxTillNow * (j - i + 1) + f(j + 1);
// f(i == n) -> return 0; base?