class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        if(N == 1) {
            return nums[0];
        }
        vector<int> dp(N, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[1], dp[0]);
        for(int i = 2; i < N; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        
        return max(dp[N - 1], dp[N - 2]);
    }
};