class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& v, int k) {
        unordered_map<int, int> mp;
        int n = v.size();
        for (int i = 1; i <= n; i++) {
            if (mp[v[i - 1]] >= max(1, i - k)) return true;
            mp[v[i - 1]] = i;
        }
        return false;
    }
};