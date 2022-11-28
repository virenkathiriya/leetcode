class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& v) {
        unordered_map<int, int> mp;
        
        for (auto &it: v) {
            int l = it[1], w = it[0];
            mp[l] = mp[w] = -2;
        }
        for (auto &it: v) {
            int l = it[1];
            mp[l]++;
        }
        vector<int> a, b;
        for (auto &[key, val]: mp) {
            if (val == -2) a.push_back(key);
            if (val == -1) b.push_back(key);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        return {a, b};
    }
};