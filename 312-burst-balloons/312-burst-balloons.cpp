class Solution {
public:
    int f(int i, int j, int n, vector<int>&v, vector<vector<int>> &dp) {
        if (i > j) return 0;
        if (dp[i][j]) return dp[i][j];
        int ans = INT_MIN;
        for (int k = i; k <= j; k++) {
            ans = max(ans, (i - 1 >= 0 ? v[i - 1]: 1) * v[k] * (j + 1 < n ? v[j + 1]: 1) + f(i, k - 1, n, v, dp) + f(k + 1, j, n, v, dp));
        }
        return dp[i][j] = ans;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        return f(0, n - 1, n, nums, dp);
    }
};
/*
    f(i, j) = 
        i > j 
            ? return 0
            : for int k = i -> j
                cost = v[i - 1] * v[k] * v[j + 1] + f(i , k - 1) + f(k + 1, j);

*/