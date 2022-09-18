class Solution {
public:
    
    int maxCoins(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n + 2, vector<int> (n + 2, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= n - 1; j++) {
                if (i > j) continue;
                int ans = INT_MIN;
                for (int k = i; k <= j; k++) {
                    ans = 
                        max(
                            ans, 
                            (i - 1 >= 0 ? v[i - 1]: 1) * v[k] * (j + 1 < n ? v[j + 1]: 1) 
                            + (k - 1 >= 0 ? dp[i][k - 1] : 0)
                            + (k + 1 < n ? dp[k + 1][j]: 0)
                        );
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n - 1];
    }
};
/*
    f(i, j) = 
        i > j 
            ? return 0
            : for int k = i -> j
                cost = v[i - 1] * v[k] * v[j + 1] + f(i , k - 1) + f(k + 1, j);

*/