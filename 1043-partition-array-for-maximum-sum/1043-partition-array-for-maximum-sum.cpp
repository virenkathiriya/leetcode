class Solution {
public:
    int f(vector<int> &v, int n, int k, int i, vector<int> &dp) {
        if (i == n) return 0;
        if (dp[i]) return dp[i];
        
        int ans = 0, maxTillNow = INT_MIN;
        for (int j = i; j < min(i + k, n); ++j) {
            maxTillNow = max(maxTillNow, v[j]);
            ans = max(ans, maxTillNow * (j - i + 1) + f(v, n, k, j + 1, dp));
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& v, int k) {
        int n = v.size();
        vector<int> dp(n + 1, 0);
        return f(v, v.size(), k, 0, dp);
    }
};
// f(i) = 
//     for j = i; j = i + k - 1; j++ 
//         maxTillNow * (j - i + 1) + f(j + 1);
// f(i == n) -> return 0; base?