class Solution {
public:
    int change(int A, vector<int>& c) {
        sort(c.begin(), c.end());
        int n = c.size();
        vector<int> dp(A + 1, 0);
        for (int i = c[0]; i <= A; i += c[0])
            dp[i] = 1;
        dp[0] = 1;
    
        for (int i = 1; i < n; i++) {
            for (int j = c[i]; j <= A; j++) {
                if (c[i] > A) {
                    i = n;
                    break;
                }
                dp[j] += dp[j - c[i]];
            }
        }
        return dp[A];
    }
};