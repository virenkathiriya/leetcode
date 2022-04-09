class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int &x: nums) mp[x]++;
        vector<int> vp;
        for (pair<int, int> p: mp) vp.push_back(p.first);
        nth_element(vp.begin(), vp.begin() + k, vp.end(), [&](const int &x, const int &y) {
            return mp[x] > mp[y];
        });
        vp.resize(k);
        return vp;
    }
};