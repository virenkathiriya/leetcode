class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); ++i) {
            int posInd = mp[target - nums[i]];
            if(posInd > 0) {
                return {posInd - 1, i};
            }
            mp[nums[i]] = i + 1;
        }
        return {-1, -1};
    }
};