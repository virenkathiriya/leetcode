class Solution {
public:
    int f(int i, vector<int> &v, int target, int cur, vector<vector<int>> &dp) {
        if (i > v.size()) 
            return 0;
        if (i == v.size()) 
            return cur == target;
        
        if (dp[i][cur + 1000] != -1) return dp[i][cur + 1000];
        return dp[i][cur + 1000] = (f(i + 1, v, target, cur + v[i], dp) + f(i + 1, v, target, cur - v[i], dp));
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int> (2001, -1));
        return f(0, nums, target, 0, dp);
    }
};