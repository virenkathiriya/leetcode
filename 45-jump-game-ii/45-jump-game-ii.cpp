class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int currentRightBound = 0;
        int ans = 0;
        int nextRightBound = 0;
        int i = 0;
        while (currentRightBound < n - 1) {
            nextRightBound = max(nextRightBound, i + nums[i]);
            if (i == currentRightBound) {
                currentRightBound = nextRightBound;
                ans++;
            }
            i++;
        }
        return ans;
    }
};