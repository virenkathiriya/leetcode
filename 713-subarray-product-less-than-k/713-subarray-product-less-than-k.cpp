class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int p = 1, ans = 0, l = 0;
        if (k < 2) return 0;
        for (int i = 0; i < nums.size(); i++) {
            p *= nums[i];
            while (p >= k) p /= nums[l++];
            ans += (i - l + 1);
        }
        return ans;
    }
};