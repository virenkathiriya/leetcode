class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& ss) {
        unordered_map<string, vector<string>> mp;
        for (string s: ss) {
            string st = s;
            sort(st.begin(), st.end());
            mp[st].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto it: mp) ans.push_back(it.second);
        return ans;
    }
};