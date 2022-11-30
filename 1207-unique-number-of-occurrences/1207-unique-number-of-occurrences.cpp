class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int &i: arr) mp[i]++;
        set<int> s;
        for (auto &it: mp) s.insert(it.second);
        return mp.size() == s.size();
    }
};