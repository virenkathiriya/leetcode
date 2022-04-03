class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        if (n < 10) return {};
        unordered_map<string, int> f;
        for (int i = 0; i < s.length() - 9; i++) f[s.substr(i, 10)]++;
        vector<string> ans;
        for (auto &it: f) if (it.second > 1) ans.push_back(it.first);
        return ans;
    }
};