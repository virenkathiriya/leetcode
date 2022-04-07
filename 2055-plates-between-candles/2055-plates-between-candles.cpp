class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& qs) {
        int n = s.size();
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (s[i] == '|')
                v.push_back(i);     
        }
        vector<int> ans;
        for (auto &q: qs) {
            int l = q[0], r = q[1];
            auto low = lower_bound(v.begin(), v.end(), l);
            if (low == v.end()) {
                ans.push_back(0);
                continue;
            }
            l = low - v.begin();
            auto high = upper_bound(v.begin(), v.end(), r);
            if (high == v.end() && v.size() > 0) {
                r = v.size() - 1;
            } else if (high != v.end()) {
                r = high - v.begin();
                r--;
            }
            if (l < r && l >= 0 && r < v.size()) {
                ans.push_back(v[r] - v[l] - r + l);
            } else {
                ans.push_back(0);
            }
        }
        return ans;
    }
};