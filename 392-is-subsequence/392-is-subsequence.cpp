class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        for (int i = 0, j = 0; i < n; i++, j++) {
            while (j < m && t[j] != s[i]) j++;
            if (j >= m) return false;
        }
        return true;
    }
};