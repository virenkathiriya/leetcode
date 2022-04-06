class Solution {
public:
    string customSortString(string o, string s) {
        vector<int> val(26, 0);
        for (int i = 0; i < o.size(); i++) val[o[i] - 'a'] = i;
        sort(s.begin(), s.end(), [&](const char &a, const char &b) {return val[a - 'a'] < val[b - 'a'];});
        return s;
    }
};