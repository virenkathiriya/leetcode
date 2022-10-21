class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int &x = nums[i];
            if (!mp[x]) mp[x] = i + 1;
            else {
                if (i - mp[x] + 1 <= k) return true;
                mp[x] = i + 1;
            }
        }
        return false;
    }
};