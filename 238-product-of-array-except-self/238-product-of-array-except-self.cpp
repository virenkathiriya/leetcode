class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero = 0;int p = 1;
        for (int &x: nums) {
            if (x == 0) {
                zero++;
                continue;
            }
            p *= x;
        }
        int n = nums.size();
        vector<int> ans(n, 0);
        if (zero > 1) return ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) ans[i] = p;
            else if (zero == 1) ans[i] = 0; 
            else ans[i] = p / nums[i];
        }
        return ans;
    }
};