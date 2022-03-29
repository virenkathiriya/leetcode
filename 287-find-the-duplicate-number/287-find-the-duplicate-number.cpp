class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            if (val < 0) {
                val *= -1;
            }
            if (nums[val - 1] < 0) {
                return val;
            } else {
                nums[val - 1] *= -1;
            }
        }
        return -1;
    }
};