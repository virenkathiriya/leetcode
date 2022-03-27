class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp1, mp2;
        for (int &x: nums1) {
            mp1[x]++;
        }
        for (int &x: nums2) {
            mp2[x]++;
        }
        for (int &x: nums1) {
            if (mp2[x] > 0 && mp1[x] > 0) mp1[x] = -1;
        }
        for (int &x: nums2) {
            if ((mp1[x] > 0 || mp1[x] < 0) && mp2[x] > 0) mp2[x] = 0;
        }
        vector<vector<int>> ans(2);
        for (auto it: mp1) {
            if (it.second > 0) ans[0].push_back(it.first);
        }
        for (auto it: mp2) {
            if (it.second > 0) ans[1].push_back(it.first);
        }
        return ans;
    }
};