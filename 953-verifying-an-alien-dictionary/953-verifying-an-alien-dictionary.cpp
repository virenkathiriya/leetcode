class Solution {
public:
    bool f(string a, string b, vector<int> &v) {
        bool ok = true;
        for (int i = 0; i < min(a.length(), b.length()); ++i) {
            int x = v[a[i] - 'a'];
            int y = v[b[i] - 'a'];
            if (x == y) continue;
            if (x < y) return true;
            else return false;
        }
        return a.size() <= b.size();
    }
    bool isAlienSorted(vector<string>& s, string o) {
        vector<int> v(26, 0);
        int m = o.size();
        for (int i = 0; i < m; i++) v[o[i] - 'a'] = i;
        for (int i = 1; i < s.size(); i++) {
            if (!f(s[i - 1], s[i], v)) return false;
        }
        return true;
    }
};