class Solution {
public:
    bool isSubsequence(string t, string s) {
        if (t.length() == 0) return true;
        for (int i = 0, j = 0; i < s.length() && j < t.length(); i++) {
            if (s[i] == t[j]) j++;
            if (j == t.length()) return true;
        }
        return false;
    }
};