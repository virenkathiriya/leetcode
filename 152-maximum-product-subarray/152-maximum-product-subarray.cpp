class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = nums[0], curMin = nums[0], res = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            int mMax = nums[i] * curMax;
            int mMin = nums[i] * curMin;
            curMax = max({mMax, mMin, nums[i]});
            curMin = min({mMax, mMin, nums[i]});
            res = max(curMax, res);
        }
        return res;
    }
};