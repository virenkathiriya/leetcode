class Solution {
public:
    const int M = 1e9 + 7;
    int f(int n, int k, int target, vector<vector<int>> &dp) {
        if (n == 0 && target == 0) return 1;
        if (target < 0 || n < 0) return 0;
        if (dp[n][target] != INT_MIN) return dp[n][target];
        
        int sum = 0;
        for (int i = 1; i <= k; ++i) sum = (sum + f(n - 1, k, target - i, dp) % M) % M;
        return dp[n][target] = sum; 
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int> (target + 1, INT_MIN));
        return f(n, k, target, dp);
    }
};